#ifndef CHARNULL_H
#define CHARNULL_H

#include "../character.h"
#include "../animationsystem.h"

class NullChar : public Character {
  private:
    AnimationSystem* animsys;
  public:
    NullChar();
    ~NullChar();
};

#endif
