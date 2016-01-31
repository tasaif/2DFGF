#ifndef JOYSTICK_H
#define JOYSTICK_H

#include <string>
#include <vector>
#include <SDL.h>
#include "button.h"
#include "sprite.h"
using namespace std;

const string legible_buttons[] = {
  "  ",
  "↑ ",
  "↓ ",
  "← ",
  "→ ",
  "↖ ",
  "↗ ",
  "↙ ",
  "↘ ",
  "S ",
  "s ",
  "□ ",
  "△ ",
  "R1",
  "L1",
  "X ",
  "O ",
  "R2",
  "L2",
  "OV",
  "TA",
  "HR",
  "EN"
};

class Joystick {
  protected:
    Joystick();
    SDL_Joystick* device = NULL;
    const unsigned buffer_size = 20;
    vector<Button> buffer;
    int raw_buffer_length = 0;
    Uint8* current_buffer = NULL;
    Uint8* previous_buffer = NULL;
    Uint8 current_hat = 0;
    Uint8 previous_hat = 0;
    Uint8* pressed_buffer = NULL;
    Button* mapping = NULL;
    Button sdlDirToButtonDir(Uint8);
    Button direction;
    Sprite* icon = NULL;

  public:
    Joystick(unsigned);
    virtual ~Joystick();
    virtual void update();
    virtual void setDefaultButtonMappings();
    virtual Uint8 Pressed(Button);
    virtual Button getDirection();
    void dumpBuffer();
    void dumpPressedBuffer();
    Sprite* getIcon();
};

#endif
