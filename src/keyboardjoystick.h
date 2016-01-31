#ifndef KEYBOARDJOYSTICK_H
#define KEYBOARDJOYSTICK_H

#include <SDL.h>
#include <unordered_map>
#include "joystick.h"
using namespace std;

class KeyboardJoystick : public Joystick {
  private:
    SDL_Scancode* mapping = NULL;
    const Uint8* keystate = NULL;
    void handle_directions();

  public:
    KeyboardJoystick(int);
    ~KeyboardJoystick();
    void update();
    void setDefaultButtonMappings();
    Uint8 Pressed(Button);
    Button getDirection();
};

#endif
