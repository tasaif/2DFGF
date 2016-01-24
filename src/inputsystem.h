#ifndef INPUTSYS_H
#define INPUTSYS_H
#include "joystick.h"

class InputSystem {
  public:
    InputSystem();
    ~InputSystem();

    Joystick* p1 = NULL;
    Joystick* p2 = NULL;

    bool pressed(Button);
};

#endif
