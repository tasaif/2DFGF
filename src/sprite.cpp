#include "sprite.h"
#include "application.h"

extern path base_path;
extern Application* app;

Sprite::Sprite(){
  offset.x = 0;
  offset.y = 0;
}

Sprite::Sprite(string fname){
  offset.x = 0;
  offset.y = 0;
  load(fname);
}

Sprite::~Sprite(){
  unload();
}

void Sprite::load(string fname){
  SDL_Surface* optimized = NULL;
  fname = (base_path / fname).string();
  unload();
  surface = IMG_Load(fname.c_str());
  if (surface == NULL){
    cout << "Failed to load: " << fname << endl;
    return;
  }

  optimized = SDL_ConvertSurface(surface, app->drawsys->format(), 0);
  if (optimized == NULL){
    cout << "Failed to optimize: " << fname << endl;
  } else {
    SDL_FreeSurface(surface);
    surface = optimized;
  }
}

void Sprite::unload(){
  if (surface != NULL){
    SDL_FreeSurface(surface);
    surface = NULL;
  }
}

bool Sprite::valid(){
  if (surface != NULL) return true;
  return false;
}

void Sprite::setPos(int x, int y){
  offset.x = x;
  offset.y = y;
}

void Sprite::align(unsigned bitmask){
  if (bitmask & HCENTER){
    offset.x = app->SCREEN_WIDTH / 2 - surface->w/2;
  }
  if (bitmask & VBOTTOM){
    offset.y = app->SCREEN_HEIGHT - surface->h;
  }
}
