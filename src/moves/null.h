#ifndef NULLMOVESYS_H
#define NULLMOVESYS_H

#include "../movesystem.h"
#include "../move.h"

class NullMoveSystem : public MoveSystem {
  private:
    vector<Move> moves;

  public:
    NullMoveSystem();
    ~NullMoveSystem();
    bool checkForMove();
};

#endif
