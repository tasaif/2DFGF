#include "movesystem.h"
#include "moves/nullmoves.h"

MoveSystem::MoveSystem(Fight* _f){
  f = _f;
  p = f->getP();
  c = p->getCharacter();
  buffer = p->joystick->getBufferAddress();
}

MoveSystem::~MoveSystem(){
}

bool MoveSystem::checkForMove(){
  switch(f->getState()){
    case psWALKF:
    case psWALKB:
    case psNEUTRAL:
      if (p->joystick->Pressed(bLP)){
        type = psNORMAL;
        number = nunLP;
        f->setSprite(c->getNormAnim(number)->primeSprite());
        return true;
      }
      break;
    default:
      break;
  }
  return false;
}

