#ifndef PLAYER_H
#define PLAYER_H

#include "joystick.h"
#include "character.h"
#include "characterindex.h"

class Player {
  public:
    Player();
    ~Player();

    CharacterIndex charselect = ciNULL;
    Joystick* joystick = NULL;
    Character* character = NULL;
};

#endif
