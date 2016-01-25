#include <iostream>
#include "joystick.h"
using namespace std;

Joystick::Joystick(){
  device = NULL;
}

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
  mapping = new Button[100]; /*
                                Supports a gamepad with up to 100 buttons
                                Change this to an unordered_map or something
                                because this is gross
                              */
  setDefaultButtonMappings();
}

Joystick::~Joystick(){
  delete mapping;
  delete pressed_buffer;
  delete previous_buffer;
  delete current_buffer;
  if (device != NULL){
    SDL_JoystickClose(device);
  }
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
  Button button;

  // Handle directional buttons
  previous_hat = current_hat;
  current_hat = SDL_JoystickGetHat(device, 0);
  button = sdlDirToButtonDir(current_hat);

  if (previous_hat != current_hat){
    if (current_hat != SDL_HAT_CENTERED){
      pressed_buffer[button] = 1;
      buffer.erase(buffer.begin());
      buffer.push_back(button);
    }
    change = true;
  } else {
    if (previous_hat != SDL_HAT_CENTERED){
      pressed_buffer[sdlDirToButtonDir(previous_hat)] = 0;
    }
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
    } else {
      pressed_buffer[mapping[i]] = 0;
    }

    if (previous_buffer[i] & !current_buffer[i]) {
      change = true;
    }
  }
  /*
   * Check for combinations here and mark them manually
   */
  if (change){
    //dumpBuffer();
    dumpPressedBuffer();
  }
}

Uint8 Joystick::Pressed(Button button){
  return pressed_buffer[button];
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
      cout << ' ';
    }
  }
  cout << "]" << endl;
}

void Joystick::dumpPressedBuffer(){
  cout << "[";
  for(unsigned i=0; i<bEND; i++){
    if (pressed_buffer[i]){
      cout << legible_buttons[i];
    } else {
      cout << "  ";
    }
  }
  cout << "]" << endl;
}
