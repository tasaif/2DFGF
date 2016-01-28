#include "player.h"
#include "application.h"

extern Application* app;

Player::Player(){
}

Player::~Player(){
}

Sprite* Player::getPlacard(){
  return app->game->charsys->getCharacter(charselect)->getPlacard();
}

Sprite* Player::getNamePlacard(){
  return app->game->charsys->getCharacter(charselect)->getNamePlacard();
}
