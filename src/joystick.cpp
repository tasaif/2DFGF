#include <iostream>
#include "joystick.h"
using namespace std;

Joystick::Joystick(unsigned sdl_joy_number){
  device = SDL_JoystickOpen(sdl_joy_number);
  SDL_JoystickEventState(SDL_ENABLE);
  raw_buffer_length = SDL_JoystickNumButtons(device);
  current_buffer = new Uint8[raw_buffer_length];
  previous_buffer = new Uint8[raw_buffer_length];
  buffer = new Button[buffer_size];
  for(unsigned i=0; i<buffer_size; i++){
    buffer[i] = bNULL;
  }
  for(int i=0; i<raw_buffer_length; i++){
    current_buffer[i] = 0;
    previous_buffer[i] = 0;
  }
}

Joystick::~Joystick(){
  delete buffer;
  delete previous_buffer;
  delete current_buffer;
  SDL_JoystickClose(device);
}

void Joystick::update(){
  for(int i=0; i<raw_buffer_length; i++){
    previous_buffer[i] = current_buffer[i];
    current_buffer[i] = SDL_JoystickGetButton(device, i);

    if (current_buffer[i]){
      cout << "Pressed: " << i << endl;
    }
  }
}

Button Joystick::lastPressed(){
  return buffer[buffer_size-1];
}
