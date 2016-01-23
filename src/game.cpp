#include "game.h"

Game::Game(){
  logo = new Billboard();
  logo->init("hello_world.bmp");
}

Game::~Game(){
  delete logo;
}

bool Game::run(){
  switch(gamestate){
    case gsNULL:
      gamestate = gsLOGO;
      logo->first();
      break;
    case gsLOGO:
      if (!logo->run()){
        gamestate = gsQUIT;
      }
      break;
    case gsINTRO:
    case gsTITLE:
    case gsOPTIONS:
    case gsCHARACTERS:
    case gsVS:
    case gsQUIT:
      return false;
  };
  return true;
}
