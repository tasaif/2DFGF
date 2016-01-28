#ifndef CHARACTERSYSTEM_H
#define CHARACTERSYSTEM_H

#include <vector>
#include "character.h"
#include "characterindex.h"
#include "characters/null.h"
using namespace std;

class CharacterSystem {
  private:
    Character** characters = NULL;
    Sprite* missing_character = NULL;

  public:
    CharacterSystem();
    ~CharacterSystem();
    Character* getCharacter(CharacterIndex);
    Sprite* getMissingCharacterIcon();
};

#endif
