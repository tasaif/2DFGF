#include "controller.h"

Controller::Controller(unsigned sdl_joy_number):Joystick(){
  device = SDL_JoystickOpen(sdl_joy_number);
  icon = new Sprite("controller.png");
  icon->align(Sprite::HCENTER);
  icon->offset.y = 105+75*sdl_joy_number;
  mapping = new int[bEND];
  for(unsigned i=0; i<bEND; i++){
    mapping[i] = -1;
  }
  setDefaultMapping();
}

Controller::~Controller(){
  delete icon;
  delete[] mapping;
  if (device != NULL){
    SDL_JoystickClose(device);
  }
}

void Controller::update(){
  unsigned sdl_button_number;
  ButtonType current_direction = getCurrentDirection();
  for(unsigned i=bUP; i<=bDOWNRIGHT; i++){
    previous_buffer[i] = current_buffer[i];
    current_buffer[i] = 0;
  }
  if (current_direction){
    current_buffer[current_direction] = 1;
  }

  for(unsigned i=0; i<bEND; i++){
    int sdl_button_number = mapping[i];
    if (sdl_button_number != -1){
      previous_buffer[i] = current_buffer[i];
      current_buffer[i] = SDL_JoystickGetButton(device, sdl_button_number);
    }
  }
  Joystick::update();
}

void Controller::setDefaultMapping(){
  mapping[bMP] = 0;
  mapping[bMK] = 1;
  mapping[bLK] = 2;
  mapping[bLP] = 3;
  mapping[bHK] = 5;
  mapping[bHP] = 7;
  mapping[bSELECT] = 8;
  mapping[bSTART] = 9;
}

ButtonType Controller::getCurrentDirection(){
  switch(SDL_JoystickGetHat(device, 0)){
    case SDL_HAT_UP:
      return bUP;
    case SDL_HAT_DOWN:
      return bDOWN;
    case SDL_HAT_LEFT:
      return bLEFT;
    case SDL_HAT_RIGHT:
      return bRIGHT;
    case SDL_HAT_RIGHTUP:
      return bUPRIGHT;
    case SDL_HAT_RIGHTDOWN:
      return bDOWNRIGHT;
    case SDL_HAT_LEFTUP:
      return bUPLEFT;
    case SDL_HAT_LEFTDOWN:
      return bDOWNLEFT;
  }
  return bNULL;
}
