#ifndef HEALTHBAR_H
#define HEALTHBAR_H

#include "sprite.h"

class HealthBar {
  private:
    unsigned width(int);
    int pnum;
    int cnter;

  public:
    static const int HPWIDTH = 240;
    static const int HPHEIGHT = 9;
    static const unsigned HPCOLOR = 0xffc71cff;
    static const unsigned REDHPCOLOR = 0xff0000dd;

    HealthBar();
    ~HealthBar();

    void init(int, int);
    Sprite* sprite;
    Sprite* bg;
    int hp;
    int redhp;
    int maxhp;
    bool dead;
    void incHealth(int);
    void update_health_bar();
    void update();
};

#endif
