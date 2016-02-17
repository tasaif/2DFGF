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
  newmove.dump();
  moves.push_back(newmove);
}

void MoveSystem::initCharacterMoves(){
  cout << "Error: initCharacterMoves being called for parent class MoveSystem" << endl;
}

vector<MoveState> MoveSystem::normalize_cmd_buffer(vector<MoveState>* mstates){
  vector<MoveState> retval;
  MoveState* tmp;
  for(unsigned i=0; i<mstates->size(); i++){
    retval.push_back((*mstates)[i].duplicate());
    tmp = &retval.back();
    if (f->isRightSide()){
      switch(tmp->button){
        case bLEFT:
          tmp->button = bRIGHT;
          break;
        case bRIGHT:
          tmp->button = bLEFT;
          break;
        case bUPLEFT:
          tmp->button = bUPRIGHT;
          break;
        case bUPRIGHT:
          tmp->button = bUPLEFT;
          break;
        case bDOWNLEFT:
          tmp->button = bDOWNRIGHT;
          break;
        case bDOWNRIGHT:
          tmp->button = bDOWNLEFT;
          break;
        default:
          break;
      };
    }
  }
  return retval;
}

bool MoveSystem::checkForMove(){
  vector<MoveState> cmd_buffer;
  vector<MoveState>* move_buffer = p->joystick->getMoveBuffer();
  int i;
  int j;
  int k;

  // Lucy, you have some splainin to do
  //if (p->getPnum() == 1){
    //p->joystick->dumpMoveBuffer();
    for(i=0; i<(int)moves.size(); i++){
      //moves[i].dump();
      cmd_buffer = normalize_cmd_buffer(moves[i].getCmd());
      j = cmd_buffer.size() - 1;
      k = move_buffer->size() - 1;
      while(k >= 0 && j >= 0 && !move_buffer->back().Confirmed()){
        if (cmd_buffer[j] == (*move_buffer)[k]){
          j--;
        }
        k--;
      }
      if (j < 0){
        move_buffer->back().Confirm();
        type = moves[i].getType();
        return true;
      }
    }
  //}
  return false;
}
