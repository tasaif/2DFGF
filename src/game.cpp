#include "game.h"

Game::Game(){
  drawsys = app->drawsys;
  hello = new Sprite("hello_world.bmp");
}

Game::~Game(){
  delete hello;
}

bool Game::run(){
  drawsys->draw(hello);
  return false;
}
