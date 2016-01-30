#include "player.h"
#include "application.h"

extern Application* app;

Player::Player(){
  healthBar = new Sprite();
}

Player::~Player(){
  delete healthBar;
}

Sprite* Player::getPlacard(unsigned player){
  return app->game->charsys->getCharacter(charselect)->getPlacard(player);
}

Sprite* Player::getNamePlacard(unsigned player){
  return app->game->charsys->getCharacter(charselect)->getNamePlacard(player);
}

Character* Player::getCharacter(){
  return app->game->charsys->getCharacter(charselect);
}

Stage* Player::getStage(){
  return app->game->charsys->getStage(charselect);
}

void Player::update_health_bar(){
  healthBar->mkRect(hpwidth(), HPHEIGHT, HPCOLOR);
}

void Player::prep(){
  maxhp = getCharacter()->getHP();
  hp = maxhp;
  update_health_bar();
}

unsigned Player::hpwidth(){
  return (unsigned)(((float)hp / (float)maxhp) * (float)HPWIDTH);
}

void Player::incHealth(int val){
  hp += val;
  update_health_bar();
}
