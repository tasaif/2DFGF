#ifndef INPUTSYS_H
#define INPUTSYS_H

#include <vector>
#include "joystick.h"
#include "keyboardjoystick.h"
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

    bool Pressed(Button);
    bool Pressed(Button, Joystick*&);
    vector<Joystick*> getJoysticks();

    void clearP(Joystick*);
    void setP1(Joystick*);
    void setP2(Joystick*);
};

#endif
