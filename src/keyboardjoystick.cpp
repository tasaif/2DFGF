#include <iostream>
#include "keyboardjoystick.h"
using namespace std;

KeyboardJoystick::KeyboardJoystick(int number_of_joysticks){
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
  icon = new Sprite("keyboard.png");
  icon->align(Sprite::HCENTER);
  icon->offset.y = 105 + 75 * number_of_joysticks;
}

KeyboardJoystick::~KeyboardJoystick(){
}

void KeyboardJoystick::handle_directions(){
  direction = bNULL;
  unsigned found = 0;
  for(unsigned i=bUP; i<=bDOWNRIGHT; i++){
    previous_buffer[i] = current_buffer[i];
    if (i <= bRIGHT){
      current_buffer[i] = (unsigned)(found < 2) & keystate[mapping[i]];
      if (current_buffer[i]){
        direction = (ButtonType)i;
        found++;
      }
    }
  }
  current_buffer[bUPLEFT] = 0;
  current_buffer[bUPRIGHT] = 0;
  current_buffer[bDOWNLEFT] = 0;
  current_buffer[bDOWNRIGHT] = 0;
  if (current_buffer[bUP]){
    if (current_buffer[bLEFT]){
      current_buffer[bUP] = 0;
      current_buffer[bLEFT] = 0;
      current_buffer[bUPLEFT] = 1;
      direction = bUPLEFT;
    } else if (current_buffer[bRIGHT]){
      current_buffer[bUP] = 0;
      current_buffer[bRIGHT] = 0;
      current_buffer[bUPRIGHT] = 1;
      direction = bUPRIGHT;
    }
  } else if (current_buffer[bDOWN]){
    if (current_buffer[bLEFT]){
      current_buffer[bDOWN] = 0;
      current_buffer[bLEFT] = 0;
      current_buffer[bDOWNLEFT] = 1;
      direction = bDOWNLEFT;
    } else if (current_buffer[bRIGHT]){
      current_buffer[bDOWN] = 0;
      current_buffer[bRIGHT] = 0;
      current_buffer[bDOWNRIGHT] = 1;
      direction = bDOWNRIGHT;
    }
  }
  if (current_buffer[bUP] && current_buffer[bDOWN]){
    current_buffer[bUP] = 0;
  } else if (current_buffer[bLEFT] && current_buffer[bRIGHT]){
    current_buffer[bLEFT] = 0;
  }
}

void KeyboardJoystick::update(){
  keystate = SDL_GetKeyboardState(NULL);
  bool change = false;

  handle_directions();
  for(unsigned i=0; i<bEND; i++){
    // directions were handled already by handle_directions()
    if (!((i <= bDOWNRIGHT) & (i >= bUP))){
      previous_buffer[i] = current_buffer[i];
      current_buffer[i] = keystate[mapping[i]];
    }
    if (!previous_buffer[i] & current_buffer[i]){
      pressed_buffer[i] = 1;
      buffer.erase(buffer.begin());
      buffer.push_back((ButtonType)i);
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
  mapping[bLK] = SDL_SCANCODE_Z;
  mapping[bMK] = SDL_SCANCODE_X;
  mapping[bHK] = SDL_SCANCODE_C;
}

Uint8 KeyboardJoystick::Pressed(ButtonType button){
  return pressed_buffer[button];
}

