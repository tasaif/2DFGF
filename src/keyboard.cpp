#include "keyboard.h"

Keyboard::Keyboard(int number_of_controllers):Joystick(){
  mapping = new SDL_Scancode[bEND];
  icon = new Sprite("keyboard.png");
  icon->align(Sprite::HCENTER);
  icon->offset.y = 105 + 75 * number_of_controllers;
  for(unsigned i=0; i<bEND; i++){
    mapping[i] = SDL_SCANCODE_UNKNOWN;
  }
  setDefaultButtonMappings();
}

Keyboard::~Keyboard(){
  delete icon;
  delete[] mapping;
}

void Keyboard::update(){
  unsigned current_scancode;
  keyboardstate = SDL_GetKeyboardState(NULL);
  if (keyboardstate != NULL){
    for(unsigned i=0; i<bEND; i++){
      current_scancode = mapping[i];
      if (current_scancode != SDL_SCANCODE_UNKNOWN){
        previous_buffer[i] = current_buffer[i];
        current_buffer[i] = keyboardstate[mapping[i]];
      }
    }
  } else {
    cout << "Error: keyboardstate is NULL" << endl;
  }
}

void Keyboard::setDefaultButtonMappings(){
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
