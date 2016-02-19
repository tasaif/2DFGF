#include "healthbar.h"

HealthBar::HealthBar(){
  sprite = new Sprite();
  bg = new Sprite();
  pnum = -1;
  cnter = 0;
}

HealthBar::~HealthBar(){
  delete sprite;
}

void HealthBar::init(int _pnum, int _maxhp){
  maxhp = _maxhp;
  pnum = _pnum;
  hp = maxhp;
  redhp = hp;
  update_health_bar();
}

void HealthBar::update_health_bar(){
  if (hp <= 0){
    dead = true;
  } else {
    sprite->mkRect(width(hp), HPHEIGHT, HPCOLOR);
  }

  if (redhp > 0){
    bg->mkRect(width(redhp), HPHEIGHT, REDHPCOLOR);
  }

  if (pnum == 0){
    sprite->setPos(44 + (HPWIDTH - width(hp)), 30);
  } else {
    sprite->setPos(0, 30);
    sprite->alignFromRight(44 + (HPWIDTH - width(hp)));
  }

  if (pnum == 0){
    bg->setPos(44 + (HPWIDTH - width(redhp)), 30);
  } else {
    bg->setPos(0, 30);
    bg->alignFromRight(44 + (HPWIDTH - width(redhp)));
  }
}

void HealthBar::incHealth(int val){
  cnter = 40;
  hp += val;
  update_health_bar();
}

unsigned HealthBar::width(int _hp){
  return (unsigned)(((float)_hp / (float)maxhp) * (float)HPWIDTH);
}

void HealthBar::update(){
  if (cnter){
    cnter--;
  } else {
    if (redhp > hp){
      redhp--;
    }
  }
  update_health_bar();
}
