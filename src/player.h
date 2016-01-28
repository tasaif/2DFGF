#ifndef PLAYER_H
#define PLAYER_H

#include "joystick.h"
#include "character.h"

class Player {
  public:
    Player();
    ~Player();

    Joystick* joystick = NULL;
    Character* character = NULL;
};

#endif
