#include "null.h"
#include "nullmoves.h"

NullMoveSystem::NullMoveSystem(){

}

NullMoveSystem::~NullMoveSystem(){
}

bool NullMoveSystem::checkForMove(){
  switch(f->getState()){
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
  }
  return false;
}
