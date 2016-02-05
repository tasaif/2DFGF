#ifndef CHARNULL_H
#define CHARNULL_H

#include "../character.h"
#include "../animationsystem.h"
#include "../moves/nullmoves.h"

class NullChar : public Character {
  private:
    AnimationSystem* animsys;

  public:
    NullChar();
    ~NullChar();
};

#endif
