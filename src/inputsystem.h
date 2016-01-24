#ifndef INPUTSYS_H
#define INPUTSYS_H

#include <vector>
#include "joystick.h"
using namespace std;

class InputSystem {
  private:
    vector<Joystick*> joysticks;

  public:
    InputSystem();
    ~InputSystem();
    void update();

    Joystick* p1 = NULL;
    Joystick* p2 = NULL;

    bool pressed(Button);
};

#endif