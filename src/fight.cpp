#include "application.h"
#include "fight.h"

Fight::Fight(Player* _p, Player* _opponent){
  p = _p;
  opponent = _opponent;
  if (p->getPnum() == 0){
    p->setPosition(Application::SCREEN_WIDTH / 4, 0);
  } else {
    p->setPosition(Application::SCREEN_WIDTH - Application::SCREEN_WIDTH / 4, 0);
  }
  currentSprite = p->getCharacter()->tmp;
}

Fight::~Fight(){
}

void Fight::run(){
  currentSprite = p->getCharacter()->tmp;
}

Sprite* Fight::getSprite(){
  return currentSprite;
}

