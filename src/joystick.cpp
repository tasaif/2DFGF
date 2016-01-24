#include "joystick.h"

Joystick::Joystick(unsigned sdl_joy_number){
  device = SDL_JoystickOpen(sdl_joy_number);
  buffer = new Button[buffer_size];
  for(unsigned i=0; i<buffer_size; i++)
    buffer[i] = bNULL;
}

Joystick::~Joystick(){
  delete buffer;
  SDL_JoystickClose(device);
}

void Joystick::update(){
}

Button Joystick::lastPressed(){
  return buffer[buffer_size-1];
}
