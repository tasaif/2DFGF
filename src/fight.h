#ifndef FIGHT_H
#define FIGHT_H

#include "player.h"
#include "playerstates.h"
#include "movesystem.h"

class MoveSystem;
class Player;
class Character;

class Fight {
  private:
    Player* p;
    Character* c;
    Player* opponent;
    Sprite* currentSprite = NULL;
    PlayerState state = psMATCHSTARTING;
    MoveSystem* movesys;
    unsigned dy_reset = 38; //qualitative
    unsigned dy;
    unsigned dx;
    unsigned distance;

    Button away = bNULL;
    Button towards = bNULL;
    Button dir = bNULL;
    int limitCheck(int);

  public:
    Fight(Player*, Player*);
    ~Fight();

    void run();
    Sprite* getSprite();
    Player* getP();
    PlayerState getState();
    void setSprite(Sprite*);
};

#endif
