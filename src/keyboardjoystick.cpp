#include <iostream>
#include "keyboardjoystick.h"
using namespace std;

KeyboardJoystick::KeyboardJoystick(){
  mapping = new SDL_Scancode[bEND];
  current_buffer = new Uint8[bEND];
  previous_buffer = new Uint8[bEND];
  pressed_buffer = new Uint8[bEND];
  for(unsigned i=0; i<bEND; i++){
    mapping[i] = (SDL_Scancode)NULL;
    current_buffer[i] = 0;
    previous_buffer[i] = 0;
    pressed_buffer[i] = 0;
  }
  for(unsigned i=0; i<buffer_size; i++){
    buffer.push_back(bNULL);
  }
  setDefaultButtonMappings();
}

KeyboardJoystick::~KeyboardJoystick(){
}

void KeyboardJoystick::update(){
  keystate = SDL_GetKeyboardState(NULL);
  bool change = false;
  for(unsigned i=0; i<bEND; i++){
    previous_buffer[i] = current_buffer[i];
    current_buffer[i] = keystate[mapping[i]];
    if (!previous_buffer[i] & current_buffer[i]){
      pressed_buffer[i] = 1;
      buffer.erase(buffer.begin());
      buffer.push_back((Button)i);
      change = true;
    } else {
      pressed_buffer[i] = 0;
    }
  }
  if (change){
    dumpPressedBuffer();
  }
}

void KeyboardJoystick::setDefaultButtonMappings(){
  mapping[bUP] = SDL_SCANCODE_UP;
  mapping[bDOWN] = SDL_SCANCODE_DOWN;
  mapping[bLEFT] = SDL_SCANCODE_LEFT;
  mapping[bRIGHT] = SDL_SCANCODE_RIGHT;
  mapping[bSTART] = SDL_SCANCODE_RETURN;
  mapping[bSELECT] = SDL_SCANCODE_SPACE;
  mapping[bLP] = SDL_SCANCODE_A;
  mapping[bMP] = SDL_SCANCODE_S;
  mapping[bHP] = SDL_SCANCODE_D;
  mapping[bTP] = SDL_SCANCODE_F;
  mapping[bLK] = SDL_SCANCODE_Z;
  mapping[bMK] = SDL_SCANCODE_X;
  mapping[bHK] = SDL_SCANCODE_C;
  mapping[bTK] = SDL_SCANCODE_V;
}

Uint8 KeyboardJoystick::Pressed(Button button){
  return pressed_buffer[button];
}
