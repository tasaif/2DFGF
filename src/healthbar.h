#ifndef HEALTHBAR_H
#define HEALTHBAR_H

#include "sprite.h"

class HealthBar {
  private:
    unsigned hpwidth();
    int pnum;

  public:
    static const int HPWIDTH = 240;
    static const int HPHEIGHT = 9;
    static const unsigned HPCOLOR = 0xffc71cff;

    HealthBar();
    ~HealthBar();

    void init(int, int);
    Sprite* sprite;
    int hp;
    int maxhp;
    bool dead;
    void incHealth(int);
    void update_health_bar();
};

#endif
