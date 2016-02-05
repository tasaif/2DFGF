#include "charactermenu.h"
#include "application.h"

extern path character_path;

VSScene::VSScene(CharacterSystem* _charsys){
  charsys = _charsys;
  optionsys = app->optionsys;
  overlay = new Sprite("overlay.png");
  time = new TextSprite();
  camera = new Camera(app->drawsys);
  time->setFont("nk57.ttf");
  time->setColor({0xff, 0xff, 0xff});
  time->init("99", 45, 0, 12);
  time->align(Sprite::HCENTER);
}

VSScene::~VSScene(){
  delete camera;
  delete time;
  delete overlay;
}

bool VSScene::first(){
  if (!initialized){
    cout << "VSScene was not initialized" << endl;
    return false;
  }
  stage = getPlayer(0)->getStage();
  camera->setStage(stage);
  match_length = optionsys->getMatchDuration();
  if (match_length){
    timer.start();
  } else {
    time->init("∞");
    time->align(Sprite::HCENTER);
  }
  getPlayer(0)->prep();
  getPlayer(1)->prep();
  getPlayer(0)->healthBar->setPos(44, 30);
  getPlayer(1)->healthBar->setPos(0, 30);
  getPlayer(1)->healthBar->alignFromRight(44);
  incHealth(0, -100);
  incHealth(1, -10);
  fightsys = new FightSystem();
  fightsys->init(getPlayer(0), getPlayer(1));
  exit_code = gsNULL;
  return true;
}

void VSScene::incHealth(unsigned player, unsigned val){
  Player* p = getPlayer(player);
  p->incHealth(val);
  if (player == 0){
    p->healthBar->offset.x = 44 + (Player::HPWIDTH - p->healthBar->surface->w);
  }
}

bool VSScene::run(){
  switch(state){
    case vssNULL:
      state = vssFIGHT;
      break;
    case vssFIGHT:
      if (match_length){
        countdown = match_length - timer.getTicks()/1000;
        time->init(to_string(countdown));
        time->align(Sprite::HCENTER);
      }
      if (countdown == 0){
        state = vssTIME;
      }
      fightsys->handleInputs();
      fightsys->resolveHitBoxes();
      break;
    case vssTIME:
      timer.stop();
      timer.start();
      state = vssFIGHT;
      break;
    default:
      break;
  };
  camera->drawBG();
  drawsys->draw(overlay);
  drawsys->draw(time);
  for(unsigned i=0; i<2; i++){
    drawsys->draw(getP(i)->healthBar);
    drawsys->draw(getCharacter(i)->getVSName(i));
  }
  fightsys->drawWith(camera);
  if (inputsys->Pressed(bSELECT)){
    exit_code = gsCHARACTERS;
  }
  if (exit_code) return false;
  return true;
}

GameState VSScene::end(){
  delete fightsys;
  timer.stop();
  return exit_code;
}

Character* VSScene::getCharacter(unsigned player){
  return app->game->getP(player)->getCharacter();
}

Player* VSScene::getP(unsigned player){
  return app->game->getP(player);
}
