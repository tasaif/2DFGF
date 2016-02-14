#include "movestate.h"

MoveState::MoveState(ButtonType _button, ButtonState _state):button(_button), state(_state){
  ttl = TTL;
  charge = 0;
}

MoveState::~MoveState(){
}

int MoveState::Ttl(int increment){
  ttl += increment;
  return ttl;
}

int MoveState::Charge(int increment){
  ttl = TTL;
  if (charge < MAXCHARGE){
    charge += increment;
  }
  return charge;
}

bool MoveState::operator==(ButtonType _button){
  return button == _button;
}
