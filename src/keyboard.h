#ifndef KEYBOARD_H
#define KEYBOARD_H

#include "joystick.h"

class Keyboard : public Joystick {
  private:
    const Uint8* keyboardstate = NULL;
    SDL_Scancode* mapping = NULL;
    void setDefaultButtonMappings();
    void fixDirections();
    bool isDirectional(ButtonType);

  public:
    Keyboard(int);
    ~Keyboard();

    void update();
};

#endif
