#include "joystick.h"

Joystick::Joystick(){
}

Joystick::~Joystick(){
}

void Joystick::update(){
  cout << "Error: virtual Joystick::update function called" << endl;
}

bool Joystick::Pressed(ButtonType button){
}

Sprite* Joystick::getIcon(){
  return icon;
}

ButtonType Joystick::getDirection(){
  return bNULL;
}
