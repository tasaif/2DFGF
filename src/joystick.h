#ifndef JOYSTICK_H
#define JOYSTICK_H

#include "buttontype.h"
#include "sprite.h"
#include "movestate.h"

class Joystick {
  protected:
    Joystick();
    Sprite* icon;
    Uint8* previous_buffer;
    Uint8* current_buffer;
    vector<MoveState> movebuffer;

  public:
    virtual ~Joystick();
    virtual void update();

    bool Pressed(ButtonType);
    Sprite* getIcon();
    ButtonType getDirection();
    void dump();
};

#endif
