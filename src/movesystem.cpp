#include "movesystem.h"

MoveSystem::MoveSystem(Fight* _f){
  f = _f;
  p = f->getP();
  c = p->getCharacter();
  buffer = p->joystick->getBufferAddress();
}

MoveSystem::~MoveSystem(){
}

void MoveSystem::calcMove(){
}

PlayerState MoveSystem::getState(PlayerState state){
  return state;
}

unsigned MoveSystem::getMoveNumber(){
  return 0;
}
