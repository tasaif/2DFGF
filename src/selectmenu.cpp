#include "menu.h"
#include "selectmenu.h"
#include "application.h"

extern Application* app;

SelectMenu::SelectMenu(){
  inputsys = app->inputsys;
  vector<Joystick*> sticks = inputsys->getJoysticks();
}

SelectMenu::~SelectMenu(){
  for(unsigned i=0; i<options.size(); i++){
    delete options[i];
  }
}

bool SelectMenu::first(){
  if (!initialized){
    cout << "SelectMenu was not initialized" << endl;
    return false;
  }
  exit_code = gsNULL;
  return true;
}

bool SelectMenu::run(){
  Joystick* curjoy;
  joysticks = inputsys->getJoysticks();
  drawsys->draw(background);
  for(unsigned i=0; i<joysticks.size(); i++){
    drawsys->draw(joysticks[i]->getIcon());
  }
  if (inputsys->Pressed(bMK)){
    exit_code = gsTITLE;
  }
  if (inputsys->Pressed(bLEFT, curjoy)){
    if (game->isPlayer(1, curjoy)){
      game->clearP(curjoy);
    } else {
      game->setP1(curjoy);
    }
  } else if (inputsys->Pressed(bRIGHT, curjoy)){
    if (game->isPlayer(0, curjoy)){
      game->clearP(curjoy);
    } else {
      game->setP2(curjoy);
    }
  }
  if (inputsys->Pressed(bLK)){
    if (game->playersReady()){
      exit_code = gsCHARACTERS;
    }
  }
  if (exit_code) return false;
  return true;
}

GameState SelectMenu::end(){
  return exit_code;
}
