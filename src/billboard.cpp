#include "billboard.h"
#include "application.h"

extern Application* app;

Billboard::Billboard(GameState next_state){
  drawsys = app->drawsys;
  background = new Sprite();
  exit_code = next_state;
}

Billboard::~Billboard(){
  delete background;
}

bool Billboard::first(){
  if (!initialized){
    cout << "Bill board was not initialized" << endl;
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

bool Billboard::init(string fname){
  return init(fname, 2000);
}

bool Billboard::init(string fname, unsigned _duration){
  if(!setBackground(fname)) return false;
  duration = _duration;
  initialized = true;
  return true;
}
