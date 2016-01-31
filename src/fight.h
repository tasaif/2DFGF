#ifndef FIGHT_H
#define FIGHT_H

#include "player.h"
#include "playerstates.h"

class Fight {
  private:
    Player* p;
    Character* c;
    Player* opponent;
    Sprite* currentSprite = NULL;
    PlayerState state = psMATCHSTARTING;
    float dy_reset = 38; //qualitative
    float dy;
    float dx;

    Button away = bNULL;
    Button towards = bNULL;
    Button dir = bNULL;

  public:
    Fight(Player*, Player*);
    ~Fight();

    void run();
    Sprite* getSprite();
};

#endif
