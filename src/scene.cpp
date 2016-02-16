#include "application.h"
#include "scene.h"

extern Application* app;

Scene::Scene(){
  indicator = new TextSprite();
  game = app->game;
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
  indicator->offset.x = option->offset.x - indicator->getW() - 2;
  indicator->offset.y = option->offset.y + option->getH()/2 - indicator->getH()/2;
}

bool Scene::init(){
  inputsys = app->inputsys;
  drawsys = app->drawsys;
  optionsys = app->optionsys;
  background = new Sprite();
  initialized = true;
  return true;
}

bool Scene::init(string fname){
  init();
  if (fname != ""){
    if(!setBackground(fname)) return false;
  }
  return true;
}

bool Scene::init(unsigned bgcolor){
  init();
  background->mkRect(Application::SCREEN_WIDTH, Application::SCREEN_HEIGHT, bgcolor);
  return true;
}

Option* Scene::createOption(unsigned _state){
  Option* retval = new Option(_state);
  options.push_back(retval);
  return retval;
}

Player* Scene::getPlayer(unsigned player){
  if (game == NULL){
    cout << "ERROR: getPlayer called without initializing game. Read scene.h" << endl;
  }
  return game->getP(player);
}
