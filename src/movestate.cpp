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

/*
 * Later, this will include:
 *  comparing charge times (sonic boom)
 *  comparing press vs release (double jump and dash)
 *
 * Right now, this is enough for a fireball cmp
 */
bool MoveState::operator==(MoveState rhs){
  if(button == rhs.button){
    return true;
  }
  return false;
}
