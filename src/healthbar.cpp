#include "healthbar.h"

HealthBar::HealthBar(){
  sprite = new Sprite();
  pnum = -1;
}

HealthBar::~HealthBar(){
  delete sprite;
}

void HealthBar::init(int _pnum, int _maxhp){
  maxhp = _maxhp;
  pnum = _pnum;
  hp = maxhp;
  update_health_bar();
}

void HealthBar::update_health_bar(){
  if (hp <= 0){
    dead = true;
  } else {
    sprite->mkRect(hpwidth(), HPHEIGHT, HPCOLOR);
  }
  if (pnum == 0){
    sprite->setPos(44 + (HPWIDTH - hpwidth()), 30);
  } else {
    sprite->setPos(0, 30);
    sprite->alignFromRight(44 + (HPWIDTH - hpwidth()));
  }
}

void HealthBar::incHealth(int val){
  hp += val;
  update_health_bar();
}

unsigned HealthBar::hpwidth(){
  return (unsigned)(((float)hp / (float)maxhp) * (float)HPWIDTH);
}
