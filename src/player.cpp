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

HitBox Player::normalize_box(HitBox hitbox){
  Animation* anim = fight->getAnim();
  Sprite* sprite = anim->currentSprite();
  bool right_side = opponent->position.x < position.x;
  if (right_side){
    hitbox.x = Application::SCREEN_WIDTH / 2 + position.x + sprite->getW()/2 - hitbox.x - hitbox.w;
  } else {
    hitbox.x = Application::SCREEN_WIDTH / 2 + position.x - sprite->getW()/2 + hitbox.x;
  }
  hitbox.y = Application::SCREEN_HEIGHT - Stage::FLOOR_HEIGHT - position.y + hitbox.y - sprite->getH();
  return hitbox;
}

vector<HitBox> Player::getDefBoxes(){
  vector<HitBox> retval;
  vector<HitBox>* def_boxes = NULL;
  if (fight->getAnim() == NULL) return retval;
  def_boxes = fight->getAnim()->currentDefBoxes();
  if (def_boxes == NULL) return retval;
  for(unsigned i=0; i<def_boxes->size(); i++){
    retval.push_back(normalize_box((*def_boxes)[i]));
  }
  return retval;
}

vector<HitBox>* Player::getAtkBoxes(){
  return &atk_boxes;
}

void Player::spawnAtkBox(HitBox box){
  atk_boxes.push_back(normalize_box(box));
}

