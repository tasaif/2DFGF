#ifndef JOYSTICK_H
#define JOYSTICK_H

#include "buttontype.h"
#include "sprite.h"

class Joystick {
  protected:
    Joystick();
    Sprite* icon;

  public:
    virtual ~Joystick();
    virtual void update();

    bool Pressed(ButtonType);
    Sprite* getIcon();
    ButtonType getDirection();
};

#endif
