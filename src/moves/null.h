#ifndef NULLMOVESYS_H
#define NULLMOVESYS_H

#include "../movesystem.h"

class NullMoveSystem : public MoveSystem {
  public:
    NullMoveSystem();
    ~NullMoveSystem();
    void initCharacterMoves();
    bool checkForMove();
};

#endif
