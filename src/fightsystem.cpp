#include "fightsystem.h"

FightSystem::FightSystem(){
  shadow = new Sprite("shadow.png");
}

FightSystem::~FightSystem(){
  delete shadow;
}

void FightSystem::init(Player* p1, Player* p2){
  p[0] = p1;
  p[1] = p2;
  f[0] = new Fight(p1, p2);
  f[1] = new Fight(p2, p1);
}

void FightSystem::handleInputs(){
  f[0]->run();
  f[1]->run();
}

void FightSystem::resolveHitBoxes(){
}

//void FightSystem::drawWith(Camera* camera, SDL_Rect _offset){
//}

void FightSystem::drawWith(Camera* camera){
  SDL_Rect center;
  center.x = (p[0]->position.x + p[1]->position.x) / 2;
  center.y = (p[0]->position.y + p[1]->position.y) / 2;
  camera->setFocus(center);
  for(unsigned i=0; i<2; i++){
    shadow->offset = p[i]->position;
    shadow->offset.y = -10;
    camera->draw(shadow);
  }
  for(unsigned i=0; i<2; i++){
    camera->draw(p[i]->position.x < p[1-i]->position.x ? f[i]->getSprite() : f[i]->getSprite()->getFlipped(), p[i]->position);
  }
}
