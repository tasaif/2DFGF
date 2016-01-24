#include "menu.h"
#include "application.h"

extern Application* app;

Menu::Menu(){
  inputsys = app->inputsys;
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
      if (inputsys->pressed(bSTART)){
        //play sound
        state = msSTARTED;
      }
      break;
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
