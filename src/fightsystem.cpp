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

void FightSystem::drawWith(DrawSystem* drawsys){
  SDL_Rect offset;
  SDL_Rect opoffset;
  Sprite* sprite;
  for(unsigned i=0; i<2; i++){
    sprite = f[i]->getSprite();
    offset = p[i]->getPosition();
    shadow->offset = offset;
    shadow->offset.x -= shadow->surface->w / 2;
    shadow->offset.y = 420 - shadow->surface->h / 2 - 10;
    opoffset = p[1-i]->getPosition();
    if (offset.x < opoffset.x){
      sprite = f[i]->getSprite();
    } else {
      sprite = f[i]->getSprite()->flipped;
    }
    drawsys->draw(shadow);
    offset.x -= sprite->surface->w / 2;
    offset.y = Application::SCREEN_HEIGHT - 60 - offset.y - sprite->surface->h;
    drawsys->draw(sprite, offset);
  }
}
