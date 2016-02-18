#ifndef FIGHT_H
#define FIGHT_H

#include "player.h"
#include "playerstates.h"
#include "movesystem.h"
#include "buttontype.h"

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
    int dy_reset = 21; //qualitative
    int dy;
    int dx;
    int distance;
    int next_step;
    int block_stun = 0;
    bool crouching = false;
    bool grounded = true;
    int knockback = 0;

    ButtonType away = bNULL;
    ButtonType towards = bNULL;
    ButtonType dir = bNULL;
    int limitCheck(int);
    void hurtHandler();
    void blockHandler();

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
    bool blocking();
    void enGarde(HitBox*);
    bool getPushed(int);
    int moveHorizontally(int);
    bool isRightSide();
    int awayMultiplier();
};

#endif
