#include "drawsystem.h"

DrawSystem::DrawSystem(){
  screen = SDL_GetWindowSurface(app->gWindow);
  cross = new Sprite("cross.png");
}

DrawSystem::~DrawSystem(){
  delete cross;
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

void DrawSystem::tick(SDL_Rect offset){
  offset.x -= cross->surface->w/2;
  offset.y -= cross->surface->h/2;
  draw(cross, offset);
}

void DrawSystem::fill(unsigned color){
  SDL_FillRect(screen, NULL, color);
}

void DrawSystem::fill(SDL_Rect offset, Uint32 color){
  SDL_FillRect(screen, &offset, SDL_MapRGBA(screen->format, (color & 0xff000000) >> 24, (color & 0xff0000) >> 16, (color & 0xff00) >> 8, color & 0xff));
}
