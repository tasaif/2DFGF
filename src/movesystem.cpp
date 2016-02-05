#include "movesystem.h"

MoveSystem::MoveSystem(){
}

void MoveSystem::init(Fight* _f){
  f = _f;
  p = f->getP();
  c = p->getCharacter();
  buffer = p->joystick->getBufferAddress();
}

MoveSystem::~MoveSystem(){
}

bool MoveSystem::checkForMove(){
  cout << "Error: checkForMove being called for parent class MoveSystem" << endl;
  return false;
}
