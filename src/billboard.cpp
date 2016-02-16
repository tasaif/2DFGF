#include "billboard.h"
#include "application.h"

extern Application* app;

Billboard::Billboard(GameState next_state){
  exit_code = next_state;
}

Billboard::~Billboard(){
}

bool Billboard::first(){
  if (!initialized){
    cout << "Billboard was not initialized" << endl;
    return false;
  }
  timer.start();
  return true;
}

bool Billboard::run(){
  drawsys->draw(background);
  if (timer.getTicks() > duration) return false;
  return true;
}

GameState Billboard::end(){
  timer.stop();
  return exit_code;
}

