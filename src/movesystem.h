#ifndef MOVESYSTEM_H
#define MOVESYSTEM_H

#include "player.h"
#include "character.h"
#include "button.h"
#include "fight.h"

class Character;
class Fight;

class MoveSystem {
  protected:
    Character* c = NULL;
    Player* p = NULL;
    Fight* f = NULL;
    vector<Button>* buffer = NULL;

  public:
    MoveSystem();
    ~MoveSystem();
    void init(Fight*);
    virtual bool checkForMove();

    PlayerState type = psNULL;
    unsigned number = 0;
};

#endif
