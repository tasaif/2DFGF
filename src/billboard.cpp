#include "billboard.h"
#include "application.h"

extern Application* app;

Billboard::Billboard(){
  drawsys = app->drawsys;
  background = new Sprite();
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

SceneExitCode Billboard::end(){
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
