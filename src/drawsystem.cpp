#include "drawsystem.h"

DrawSystem::DrawSystem(){
  screen = SDL_GetWindowSurface(app->gWindow);
}

DrawSystem::~DrawSystem(){
}

void DrawSystem::draw(Sprite* sprite){
  draw(sprite, sprite->offset);
}

void DrawSystem::draw(Sprite* sprite, SDL_Rect offset){
  if (sprite == NULL){
    cout << "Error: Tried to draw NULL sprite" << endl;
  } else if (sprite->surface == NULL){
    cout << "Error: Tried to draw NULL sprite->surface" << endl;
  } else {
    SDL_BlitSurface(sprite->surface, NULL, screen, &offset);
  }
}

SDL_PixelFormat* DrawSystem::format(){
  return screen->format;
}
