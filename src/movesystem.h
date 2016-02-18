#ifndef MOVESYSTEM_H
#define MOVESYSTEM_H

#include "player.h"
#include "character.h"
#include "buttontype.h"
#include "fight.h"
#include "move.h"

class Character;
class Fight;

class MoveSystem {
  protected:
    Character* c = NULL;
    Player* p = NULL;
    Fight* f = NULL;
    vector<Move> moves;
    void mkMove(string, Animation*, unsigned, PlayerState, string);
    vector<MoveState> normalize_cmd_buffer(vector<MoveState>*);

  public:
    MoveSystem();
    virtual ~MoveSystem();
    void init(Fight*);
    virtual void initCharacterMoves();
    virtual bool checkForMove();

    PlayerState type = psNULL;
    unsigned index = 0;
};

#endif
