#include "menu.h"
#include "application.h"

extern Application* app;

Menu::Menu(){
  inputsys = app->inputsys;
  drawsys = app->drawsys;
  background = new Sprite();

  start_option = new Option();
  start_option->init("Press Start", 24, 0, 300);
  start_option->align(
    Sprite::HCENTER
  );

  vs_option = new Option();
  vs_option->init("2P Versus", 24, 0, 300);
  vs_option->align(
    Sprite::HCENTER
  );
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
    case msNULL:
      drawsys->draw(start_option);
      if (inputsys->pressed(bSTART)){
        //play sound
        state = msVS;
      }
      break;
    case msVS:
      drawsys->draw(vs_option);
      break;
    case msOPTIONS:
      break;
    case msQUIT:
      return false;
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
