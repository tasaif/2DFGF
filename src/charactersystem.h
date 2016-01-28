#ifndef CHARACTERSYSTEM_H
#define CHARACTERSYSTEM_H

#include <vector>
#include "character.h"
using namepspace std;

class CharacterSystem {
  private:
    vector<Character*> characters;

  public:
    CharacterSystem();
    ~CharacterSystem();
};

#endif
