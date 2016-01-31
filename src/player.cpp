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

int Player::getPnum(){
  return pnum;
}

void Player::setP(int _pnum){
  pnum = _pnum;
}

void Player::setPosition(int _x){
  position.x = _x;
}

void Player::setPosition(int _x, int _y){
  position.x = _x;
  position.y = _y;
}

SDL_Rect Player::getPosition(){
  return position;
}
