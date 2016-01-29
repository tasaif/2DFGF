#ifndef CHARACTERSYSTEM_H
#define CHARACTERSYSTEM_H

#include <vector>
#include "character.h"
#include "stage.h"
#include "characterindex.h"
#include "characters/null.h"
#include "stages/null.h"
using namespace std;

class CharacterSystem {
  private:
    Character** characters = NULL;
    Stage** stages = NULL;
    Sprite* missing_character = NULL;

  public:
    CharacterSystem();
    ~CharacterSystem();
    Character* getCharacter(CharacterIndex);
    Sprite* getMissingCharacterIcon();
    Stage* getStage(CharacterIndex);
};

#endif
