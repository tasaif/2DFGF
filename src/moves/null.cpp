#include "null.h"
#include "nullmoves.h"

NullMoveSystem::NullMoveSystem(){
}

NullMoveSystem::~NullMoveSystem(){
}

// This is not in the constructor because of an ordering issue
void NullMoveSystem::initCharacterMoves(){
  mkMove("236236lP", c->getSpecAnim(nusFIREBALL), nusFIREBALL, psSPECIAL, "SUPERFIREBALL");
  mkMove("623lP", c->getSpecAnim(nusFIREBALL), nusFIREBALL, psSPECIAL, "DP");
  mkMove("236lP", c->getSpecAnim(nusFIREBALL), nusFIREBALL, psSPECIAL, "FIREBALL");
}

bool NullMoveSystem::checkForMove(){
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
  /*switch(f->getState())
    case psWALKF:
    case psWALKB:
    case psNEUTRAL:
      if (p->joystick->Pressed(bHP)){
        type = psNORMAL;
        number = nunHP;
        f->setSprite(c->getNormAnim(number)->primeSprite());
        return true;
      } else if (p->joystick->Pressed(bLP)){
        type = psNORMAL;
        number = nunLP;
        f->setSprite(c->getNormAnim(number)->primeSprite());
        return true;
      } else if (p->joystick->Pressed(bMP)){
        type = psSPECIAL;
        number = nusFIREBALL;
        f->setSprite(c->getSpecAnim(number)->primeSprite());
        return true;
      }
      break;
    default:
      break;
  }*/
  return false;
}
