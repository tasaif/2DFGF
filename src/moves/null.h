#ifndef NULLMOVESYS_H
#define NULLMOVESYS_H

#include "../movesystem.h"

class NullMoveSystem : public MoveSystem {
  private:
  public:
    NullMoveSystem();
    ~NullMoveSystem();
    bool checkForMove();
};

#endif
