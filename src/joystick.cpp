#include <iostream>
#include "joystick.h"
using namespace std;

Joystick::Joystick(unsigned sdl_joy_number){
  device = SDL_JoystickOpen(sdl_joy_number);
  raw_buffer_length = SDL_JoystickNumButtons(device);
  current_buffer = new Uint8[raw_buffer_length];
  previous_buffer = new Uint8[raw_buffer_length];
  pressed_buffer = new Uint8[bEND];
  for(unsigned i=0; i<buffer_size; i++){
    buffer.push_back(bNULL);
  }
  for(int i=0; i<raw_buffer_length; i++){
    current_buffer[i] = 0;
    previous_buffer[i] = 0;
  }
  for(unsigned i=0; i<bEND; i++){
    pressed_buffer[i] = bNULL;
  }
  mapping = new Button[100]; //Supports a gamepad with up to 100 buttons
  setDefaultButtonMappings();
}

Joystick::~Joystick(){
  delete mapping;
  delete pressed_buffer;
  delete previous_buffer;
  delete current_buffer;
  SDL_JoystickClose(device);
}

Button Joystick::sdlDirToButtonDir(Uint8 dir){
  switch(dir){
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

void Joystick::update(){
  bool change = false;

  // Handle directional buttons
  previous_hat = current_hat;
  current_hat = SDL_JoystickGetHat(device, 0);
  if (current_hat != SDL_HAT_CENTERED && previous_hat != current_hat){
    buffer.erase(buffer.begin());
    buffer.push_back(sdlDirToButtonDir(current_hat));
    change = true;
  }

  // Handle nondirectional buttons
  for(int i=0; i<raw_buffer_length; i++){
    previous_buffer[i] = current_buffer[i];
    current_buffer[i] = SDL_JoystickGetButton(device, i);
    if (!previous_buffer[i] & current_buffer[i]){
      pressed_buffer[mapping[i]] = 1;
      buffer.erase(buffer.begin());
      buffer.push_back(mapping[i]);
      change = true;
    }
  }
  /*
   * Check for combinations here and mark them manually
   */
  if (change){
    dumpBuffer();
  }
}

Button Joystick::lastPressed(){
  return buffer[buffer_size-1];
}

void Joystick::setDefaultButtonMappings(){
  mapping[0] = bMP;
  mapping[1] = bMK;
  mapping[2] = bLK;
  mapping[3] = bLP;
  mapping[4] = bTK;
  mapping[5] = bHK;
  mapping[6] = bTP;
  mapping[7] = bHP;
  mapping[8] = bSELECT;
  mapping[9] = bSTART;
}

void Joystick::dumpBuffer(){
  cout << "[";
  for(unsigned i=0; i<buffer.size(); i++){
    cout << legible_buttons[buffer[i]];
    if (i != buffer.size()-1){
      cout << ", ";
    }
  }
  cout << "]" << endl;
}
