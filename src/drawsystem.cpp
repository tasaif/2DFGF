#include "drawsystem.h"

DrawSystem::DrawSystem(){
  renderer = SDL_CreateRenderer(app->window, -1, SDL_RENDERER_TARGETTEXTURE);
  if (renderer == NULL){
    cout << "Error: renderer could not be created \"" << SDL_GetError() << "\"" << endl;
  }
  SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
  app->renderer = renderer;
  cross = new Sprite("cross.png");
}

DrawSystem::~DrawSystem(){
  delete cross;
  SDL_DestroyRenderer(renderer);
}

void DrawSystem::draw(Sprite* sprite){
  draw(sprite, sprite->offset);
}

void DrawSystem::draw(Sprite* sprite, SDL_Rect offset){
  if (sprite == NULL){
    cout << "Error: Tried to draw NULL sprite" << endl;
  } else if (sprite->texture == NULL){
    cout << "Error: Tried to draw NULL sprite->texture" << endl;
  } else {
    SDL_RenderCopyEx(renderer, sprite->texture, NULL, &offset, sprite->getAngle(), sprite->getRotationPoint(), sprite->getFlipState());
  }
}

void DrawSystem::tick(SDL_Rect offset){
  offset.x -= cross->getW()/2;
  offset.y -= cross->getH()/2;
  draw(cross, offset);
}

void DrawSystem::fill(unsigned color){
  SDL_Rect rect;
  rect.x = 0;
  rect.y = 0;
  rect.w = app->SCREEN_WIDTH;
  rect.h = app->SCREEN_HEIGHT;
  fill(rect, color);
}

void DrawSystem::fill(SDL_Rect rect, Uint32 color){
  SDL_SetRenderDrawColor(renderer, (color & 0xff000000) >> 24, (color & 0xff0000) >> 16, (color & 0xff00) >> 8, color & 0xff);
  SDL_RenderFillRect(renderer, &rect);
}

SDL_Renderer* DrawSystem::getRenderer(){
  return renderer;
}

void DrawSystem::update(){
  SDL_RenderPresent(renderer);
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
}
