#include "menu.h"
#include "application.h"

extern Application* app;

Menu::Menu(){
  drawsys = app->drawsys;
  background = new Sprite();
}

Menu::~Menu(){
  delete background;
}

bool Menu::first(){
  if (!initialized){
    cout << "Menu was not initialized" << endl;
    return false;
  }
  timer.start();
  return true;
}

bool Menu::run(){
  switch(state){
    case msNULL:
    case msSTARTED:
    case msOPTIONS:
    case msVS:
      break;
  };
  drawsys->draw(background);
  return true;
}

SceneExitCode Menu::end(){
  return exit_code;
}

bool Menu::init(string fname){
  if(!setBackground(fname)) return false;
  initialized = true;
  return true;
}
