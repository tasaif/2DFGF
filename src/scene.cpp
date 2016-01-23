#include "scene.h"

Scene::Scene(){
}

Scene::~Scene(){
}

bool Scene::setBackground(string fname){
  background->load(fname);
  return background->valid();
}
