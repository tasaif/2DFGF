#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "joystick.h"

class Controller : public Joystick {
  private:
  public:
    Controller(unsigned);
    ~Controller();

    void update();
};

#endif
