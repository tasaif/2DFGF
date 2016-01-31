#ifndef FIGHT_H
#define FIGHT_H

#include "player.h"
#include "playerstates.h"

class Fight {
  private:
    Player* p;
    Player* opponent;
    Sprite* currentSprite = NULL;
    PlayerState state = psMATCHSTARTING;

  public:
    Fight(Player*, Player*);
    ~Fight();

    void run();
    Sprite* getSprite();
};

#endif
