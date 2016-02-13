#ifndef INPUTSYS_H
#define INPUTSYS_H

#include <vector>
#include "joystick.h"
#include "keyboard.h"
#include "controller.h"
#include "game.h"
#include "player.h"
using namespace std;

class Game;

class InputSystem {
  private:
    vector<Joystick*> joysticks;
    Game* game = NULL;

  public:
    InputSystem();
    ~InputSystem();
    void update();

    bool Pressed(ButtonType);
    bool Pressed(ButtonType, Joystick*&);
    vector<Joystick*> getJoysticks();
};

#endif
