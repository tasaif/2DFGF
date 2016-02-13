#ifndef KEYBOARD_H
#define KEYBOARD_H

#include "joystick.h"

class Keyboard : public Joystick {
  private:
  public:
    Keyboard(int);
    ~Keyboard();

    void update();
};

#endif
