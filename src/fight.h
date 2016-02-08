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
    Sprite* prevSprite = NULL;
    Sprite* currentSprite = NULL;
    Animation* currentAnim = NULL;
    PlayerState previous_state = psNULL;
    PlayerState state = psMATCHSTARTING;
    MoveSystem* movesys;
    unsigned dy_reset = 38; //qualitative
    unsigned dy;
    unsigned dx;
    unsigned distance;
    int stun_timer = 0;

    Button away = bNULL;
    Button towards = bNULL;
    Button dir = bNULL;
    int limitCheck(int);

  public:
    Fight(Player*, Player*);
    ~Fight();

    void run();
    Sprite* getSprite();
    Animation* getAnim();
    Player* getP();
    PlayerState getState();
    void setSprite(Sprite*);
    void setStunTimer(PlayerState, int);
    void hitBy(PlayerState);
};

#endif
