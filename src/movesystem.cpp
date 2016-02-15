#include "movesystem.h"

MoveSystem::MoveSystem(){
}

void MoveSystem::init(Fight* _f){
  f = _f;
  p = f->getP();
  c = p->getCharacter();
}

MoveSystem::~MoveSystem(){
}

void MoveSystem::mkMove(string _command, Animation* _anim, unsigned _move_number, PlayerState _type, string _name){
  Move newmove;
  newmove.init(_command, _anim, _move_number, _type, _name);
  moves.push_back(newmove);
}

void MoveSystem::initCharacterMoves(){
  cout << "Error: initCharacterMoves being called for parent class MoveSystem" << endl;
}

bool MoveSystem::checkForMove(){
  cout << "Error: checkForMove being called for parent class MoveSystem" << endl;
  return false;
}
