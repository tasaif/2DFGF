#include "sprite.h"
#include "application.h"

extern path base_path;
extern Application* app;

Sprite::Sprite(){
}

Sprite::Sprite(string fname){
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
