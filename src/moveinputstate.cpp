#include "moveinputstate.h"

Button::Button(){
  ttl = TTL;
  charge = 0;
}

Button::~Button(){
}

void Button::push(ButtonType _type){
  types.push_back(_type);
}

