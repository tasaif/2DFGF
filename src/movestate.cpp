#include "movestate.h"

#include <iostream>
using namespace std;

MoveState::MoveState(ButtonType _button, ButtonState _state){
  button = _button;
  state = _state;
  ttl = TTL;
  confirmed = false;
  charge = 0;
}

MoveState::MoveState(ButtonType _button, ButtonState _state, int _charge){
  button = _button;
  state = _state;
  ttl = TTL;
  confirmed = false;
  charge = _charge;
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

/*
 * Later, this will include:
 *  comparing charge times (sonic boom)
 *
 */
bool MoveState::operator==(MoveState rhs){
  if(button == rhs.button){
    if (state == bsNULL || rhs.state == bsNULL){
      return false;
    } else {
      if (state == rhs.state){
        return true;
      }
    }
  }
  return false;
}

void MoveState::Confirm(){
  confirmed = true;
}

bool MoveState::Confirmed(){
  return confirmed;
}

MoveState MoveState::duplicate(){
  MoveState retval = MoveState(button, state, charge);
  retval.Ttl(ttl);
  if (confirmed) retval.Confirm();
  return retval;
}

void MoveState::dump(){
  cout << "(" << legible_buttons[button] << "," << legible_button_states[state] << ") ";
}
