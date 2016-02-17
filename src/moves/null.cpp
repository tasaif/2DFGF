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
}
