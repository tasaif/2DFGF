#include "menu.h"
#include "application.h"

extern Application* app;

Menu::Menu(){
  inputsys = app->inputsys;
  drawsys = app->drawsys;
  background = new Sprite();
  start_option = new Option("Press Start");
}

Menu::~Menu(){
  delete start_option;
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
  drawsys->draw(background);
  switch(state){
    drawsys->draw(start_option);
    case msNULL:
      if (inputsys->pressed(bSTART)){
        //play sound
        state = msSTARTED;
      }
      break;
    case msSTARTED:
      return false;
    case msOPTIONS:
    case msVS:
      break;
  };
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
