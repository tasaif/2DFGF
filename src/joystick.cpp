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
  ButtonType button;
  bool pressed;
  bool held;
  bool released;

  // Update the movebuffer with new states
  for(unsigned i=0; i<bEND; i++){
    button = (ButtonType)i;
    pressed = !previous_buffer[i] && current_buffer[i];
    held = previous_buffer[i] && current_buffer[i];
    released = previous_buffer[i] && !current_buffer[i];
    if (pressed || released){
      movebuffer.push_back(MoveState(button, pressed?bsPRESSED:bsRELEASED));
    } else if(held) {
      for(unsigned i=movebuffer.size()-1; i>=0; i--){
        if (movebuffer[i].button == button){
          movebuffer[i].Charge(1);
          break;
        }
      }
    }
  }

  // Increment TTL values
  for(unsigned i=0; i<movebuffer.size(); i++){
    if(movebuffer[i].Ttl(-1) < 0){
      movebuffer.erase(movebuffer.begin() + i);
      i--;
    }
  }
}

void Joystick::dumpStates(){
  cout << "Joystick previous_buffer: ";
  for(unsigned i=0; i<bEND; i++){
    if (previous_buffer[i]){
      cout << legible_buttons[i] << ' ';
    }
  }
  cout << endl;
  cout << "Joystick current_buffer:  ";
  for(unsigned i=0; i<bEND; i++){
    if (current_buffer[i]){
      cout << legible_buttons[i] << ' ';
    }
  }
  cout << endl;
}

void Joystick::dumpMoveBuffer(){
  MoveState* ms;
  cout << "Joystick Dump: ";
  for(unsigned i=0; i<movebuffer.size(); i++){
    ms = &movebuffer[i];
    cout << legible_button_states[ms->state] << legible_buttons[ms->button] << ' ';
  }
  cout << endl;
}

bool Joystick::Pressed(ButtonType button){
  return !previous_buffer[button] && current_buffer[button];
}

Sprite* Joystick::getIcon(){
  return icon;
}

ButtonType Joystick::getDirection(){
  for(unsigned i=bUP; i<=bDOWNRIGHT; i++){
    if (current_buffer[i]){
      return (ButtonType)i;
    }
  }
  return bNULL;
}

vector<MoveState>* Joystick::getMoveBuffer(){
  return &movebuffer;
}
