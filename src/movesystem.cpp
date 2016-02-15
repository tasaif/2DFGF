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
  vector<MoveState>* cmd_buffer;
  vector<MoveState>* move_buffer = p->joystick->getMoveBuffer();
  MoveState* cmd_ms;
  MoveState* input_ms;
  int i;
  int j;
  int k;
  bool found_ms;

  // Lucy, you have some splainin to do
  if (p->getPnum() == 1){
    p->joystick->dumpStates();
    p->joystick->dumpMoveBuffer();
    for(i=0; i<moves.size(); i++){
      cout << "Checking for " << moves[i].getName() << ": ";
      moves[i].dump(false);
      cmd_buffer = moves[i].getCmd();
      j = cmd_buffer->size() - 1;
      k = move_buffer->size() - 1;
      while (j >= 0){
        while (k >= 0){
          if ((*move_buffer)[k] == (*cmd_buffer)[j]){
            break;
          }
          k--;
        }
        if (k < 0){
          break;
        }
        j--;
      }
      if (j < 0){
        cout << "TRUE" << endl;
      } else {
        cout << "FALSE" << endl;
      }
    }
    cout << endl;
  }
  return false;
}
