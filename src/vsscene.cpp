#include "charactermenu.h"
#include "application.h"

VSScene::VSScene(CharacterSystem* _charsys){
  charsys = _charsys;
  optionsys = app->optionsys;
}

VSScene::~VSScene(){
}

bool VSScene::first(){
  if (!initialized){
    cout << "VSScene was not initialized" << endl;
    return false;
  }
  stage = getPlayer(0)->getStage();
  exit_code = gsNULL;
  return true;
}

bool VSScene::run(){
  stage->draw();
  if (inputsys->Pressed(bMK)){
    exit_code = gsCHARACTERS;
  }
  if (exit_code) return false;
  return true;
}

GameState VSScene::end(){
  return exit_code;
}

Character* VSScene::getCharacter(unsigned player){
  return app->game->getP(player)->getCharacter();
}

Player* VSScene::getP(unsigned player){
  return app->game->getP(player);
}
