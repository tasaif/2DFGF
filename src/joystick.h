#ifndef JOYSTICK_H
#define JOYSTICK_H
#include <SDL2/SDL.h>

enum Button {
  bNULL,
  bUP,
  bDOWN,
  bLEFT,
  bRIGHT,
  bUPLEFT,
  bUPRIGHT,
  bDOWNLEFT,
  bDOWNRIGHT,
  bSTART,
  bSELECT,
  bLP,
  bMP,
  bHP,
  bTP,
  bLK,
  bMK,
  bHK,
  bTK,
  bOVERHEAD,
  bTAUNT
};

class Joystick {
  private:
    SDL_Joystick* device;
    const unsigned buffer_size = 20;
    Button* buffer = NULL;

  public:
    Joystick(unsigned);
    ~Joystick();
    void update();
    Button lastPressed();
};

#endif
