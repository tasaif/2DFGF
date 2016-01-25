#include "scene.h"

Scene::Scene(){
  indicator = new TextSprite();
}

Scene::~Scene(){
  delete indicator;
}

bool Scene::setBackground(string fname){
  background->load(fname);
  return background->valid();
}

void Scene::setIndicatorPos(Option* option){
  indicator->offset.x = option->offset.x - indicator->surface->w - 2;
  indicator->offset.y = option->offset.y + option->surface->h/2 - indicator->surface->h/2;
}
