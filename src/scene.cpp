#include "application.h"
#include "scene.h"

extern Application* app;

Scene::Scene(){
  indicator = new TextSprite();
}

Scene::~Scene(){
  delete indicator;
  delete background;
  for(unsigned i=0; i<options.size(); i++){
    delete options[i];
  }
}

bool Scene::setBackground(string fname){
  background->load(fname);
  return background->valid();
}

void Scene::setIndicatorPos(Option* option){
  indicator->offset.x = option->offset.x - indicator->surface->w - 2;
  indicator->offset.y = option->offset.y + option->surface->h/2 - indicator->surface->h/2;
}

bool Scene::init(string fname){
  inputsys = app->inputsys;
  drawsys = app->drawsys;
  optionsys = app->optionsys;
  background = new Sprite();
  if(!setBackground(fname)) return false;
  initialized = true;
  return true;
}

Option* Scene::createOption(unsigned _state){
  Option* retval = new Option(_state);
  options.push_back(retval);
  return retval;
}
