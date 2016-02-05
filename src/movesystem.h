#ifndef MOVESYSTEM_H
#define MOVESYSTEM_H

#include "player.h"
#include "character.h"
#include "button.h"

class Character;

class MoveSystem {
  private:
    Character* c = NULL;
    Player* p = NULL;
    vector<Button>* buffer = NULL;

  public:
    MoveSystem(Character*, Player*);
    ~MoveSystem();
    void setPlayerBuffer(vector<Button>*);

    void calcMove();
    PlayerState getState(PlayerState);
    unsigned getMoveNumber();
};

#endif
