#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "joystick.h"

class Controller : public Joystick {
  private:
    SDL_Joystick* device = NULL;
    void setDefaultMapping();
    ButtonType getCurrentDirection();
    int* mapping;

  public:
    Controller(unsigned);
    ~Controller();

    void update();
};

#endif
