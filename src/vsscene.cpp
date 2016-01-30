#include "charactermenu.h"
#include "application.h"

extern path character_path;

VSScene::VSScene(CharacterSystem* _charsys){
  charsys = _charsys;
  optionsys = app->optionsys;
  overlay = new Sprite("overlay.png");
  tmpplayer1 = new Sprite(character_path, "null/animations/breathing/null-0.png");
  tmpplayer2 = tmpplayer1->duplicate();
  tmpplayer2->flipHorizontal();
  tmpplayer1->setPos(93, 235);
  tmpplayer2->setPos(441, 235);
  time = new TextSprite();
  time->setFont("nk57.ttf");
  time->setColor({0xff, 0xff, 0xff});
  time->init("99", 45, 0, 12);
  time->align(Sprite::HCENTER);
}

VSScene::~VSScene(){
  delete tmpplayer1;
  delete tmpplayer2;
  delete time;
  delete overlay;
}

bool VSScene::first(){
  if (!initialized){
    cout << "VSScene was not initialized" << endl;
    return false;
  }
  stage = getPlayer(0)->getStage();
  match_length = optionsys->getMatchDuration();
  if (match_length){
    timer.start();
  } else {
    time->init("∞");
    time->align(Sprite::HCENTER);
  }
  exit_code = gsNULL;
  return true;
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
      break;
    case vssTIME:
      timer.stop();
      timer.start();
      state = vssFIGHT;
      break;
    default:
      break;
  };
  stage->draw();
  drawsys->draw(overlay);
  drawsys->draw(time);
  drawsys->draw(tmpplayer1);
  drawsys->draw(tmpplayer2);
  if (inputsys->Pressed(bMK)){
    exit_code = gsCHARACTERS;
  }
  if (exit_code) return false;
  return true;
}

GameState VSScene::end(){
  timer.stop();
  return exit_code;
}

Character* VSScene::getCharacter(unsigned player){
  return app->game->getP(player)->getCharacter();
}

Player* VSScene::getP(unsigned player){
  return app->game->getP(player);
}
