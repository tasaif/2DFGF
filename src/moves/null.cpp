#include "null.h"
#include "nullmoves.h"

NullMoveSystem::NullMoveSystem(){
}

NullMoveSystem::~NullMoveSystem(){
}

// This is not in the constructor because of an ordering issue
void NullMoveSystem::initCharacterMoves(){
  mkMove("DlPDlPD6DlKDhP", c->getSpecAnim(nusFIREBALL), nusFIREBALL, psSPECIAL, "天");
  mkMove("236236lP", c->getSpecAnim(nusFIREBALL), nusFIREBALL, psSPECIAL, "SUPERFIREBALL");
  mkMove("623lP", c->getSpecAnim(nusFIREBALL), nusFIREBALL, psSPECIAL, "DP");
  mkMove("236lP", c->getSpecAnim(nusFIREBALL), nusFIREBALL, psSPECIAL, "FIREBALL");
  mkMove("66", c->getBaseAnim(psDASHF), NULL, psDASHF, "DASHF");
  mkMove("44", c->getBaseAnim(psDASHB), NULL, psDASHB, "DASHB");
}

bool NullMoveSystem::checkForMove(){
  return MoveSystem::checkForMove();
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
