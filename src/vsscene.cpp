#include "charactermenu.h"
#include "application.h"

extern path character_path;

VSScene::VSScene(CharacterSystem* _charsys){
  charsys = _charsys;
  optionsys = app->optionsys;
  overlay = new Sprite("overlay.png");
  time = new TextSprite();
  camera = new Camera(app->drawsys);
  time->setFont("andrew-bulhak_modeseven/MODES___.TTF");
  time->setColor({0xff, 0xff, 0xff});
  time->init("99", 45, 0, 12);
  time->align(Sprite::HCENTER);
  bgm->load("null1024_-_impossible.wav");
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
  fightsys = new FightSystem(app->sparksys);
  fightsys->init(getPlayer(0), getPlayer(1));
  exit_code = gsNULL;
  bgm->play();
  return true;
}

void VSScene::incHealth(unsigned player, unsigned val){
  Player* p = getPlayer(player);
  p->health.incHealth(val);
  if (player == 0){
    p->health.sprite->offset.x = 44 + (HealthBar::HPWIDTH - p->health.sprite->getW());
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
  HealthBar* hb;
  for(unsigned i=0; i<2; i++){
    hb = &getP(i)->health;
    hb->update();
    if (hb->redhp > 0){
      drawsys->draw(hb->bg);
    }
    if (!hb->dead){
      drawsys->draw(hb->sprite);
    }
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
