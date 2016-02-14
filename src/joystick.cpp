#include "joystick.h"

Joystick::Joystick(){
  previous_buffer = new Uint8[bEND];
  current_buffer = new Uint8[bEND];
  for(unsigned i=0; i<bEND; i++){
    previous_buffer[i] = 0;
    current_buffer[i] = 0;
  }
}

Joystick::~Joystick(){
  delete[] previous_buffer;
  delete[] current_buffer;
}

void Joystick::update(){
  cout << "Error: virtual Joystick::update function called" << endl;
}

bool Joystick::Pressed(ButtonType button){
  return !previous_buffer[button] && current_buffer[button];
}

Sprite* Joystick::getIcon(){
  return icon;
}

ButtonType Joystick::getDirection(){
  return bNULL;
}
