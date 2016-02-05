#ifndef MOVESYSTEM_H
#define MOVESYSTEM_H

#include "player.h"
#include "character.h"
#include "button.h"
#include "fight.h"

class Character;
class Fight;

class MoveSystem {
  private:
    Character* c = NULL;
    Player* p = NULL;
    Fight* f = NULL;
    vector<Button>* buffer = NULL;

  public:
    MoveSystem(Fight*);
    ~MoveSystem();

    void calcMove();
    PlayerState getState(PlayerState);
    unsigned getMoveNumber();
};

#endif
