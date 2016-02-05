#include "movesystem.h"

MoveSystem::MoveSystem(Character* _c, Player* _p){
  c = _c;
  p = _p;
  buffer = p->joystick->getBufferAddress();
}

MoveSystem::~MoveSystem(){
}

void MoveSystem::setPlayerBuffer(vector<Button>* _buffer){
  buffer = _buffer;
}

void MoveSystem::calcMove(){
}

PlayerState MoveSystem::getState(PlayerState state){
  return state;
}

unsigned MoveSystem::getMoveNumber(){
  return 0;
}
