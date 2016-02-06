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
  //return app->game->charsys->getCharacter(charselect);
  return character;
}

Stage* Player::getStage(){
  return app->game->charsys->getStage(charselect);
}

void Player::update_health_bar(){
  healthBar->mkRect(hpwidth(), HPHEIGHT, HPCOLOR);
}

void Player::prep(){
  if (character == NULL){
    character = app->game->charsys->mkCharacter(charselect);
  }
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

SDL_Rect Player::normalize_box(SDL_Rect hitbox){
  bool right_side = opponent->position.x > position.x;
  hitbox.x = position.x + (right_side ? 1 : -1) * hitbox.x;
  hitbox.y = position.y + hitbox.y;
  return hitbox;
}

vector<SDL_Rect> Player::getDefBoxes(){
  vector<SDL_Rect> retval;
  vector<SDL_Rect>* def_boxes = NULL;
  if (fight->getAnim() == NULL) return retval;
  def_boxes = fight->getAnim()->currentDefBoxes();
  if (def_boxes == NULL) return retval;
  for(unsigned i=0; i<def_boxes->size(); i++){
    retval.push_back(normalize_box((*def_boxes)[i]));
  }
  return retval;
}

vector<SDL_Rect> Player::getAtkBoxes(){
  vector<SDL_Rect> retval;
  vector<SDL_Rect>* atk_boxes = NULL;
  if (fight->getAnim() == NULL) return retval;
  atk_boxes = fight->getAnim()->currentAtkBoxes();
  if (atk_boxes == NULL) return retval;
  for(unsigned i=0; i<atk_boxes->size(); i++){
    retval.push_back(normalize_box((*atk_boxes)[i]));
  }
  return retval;
}
