#include "sprite.h"
#include "application.h"

extern path image_path;

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
  fname = (image_path / fname).string();
  unload();
  surface = IMG_Load(fname.c_str());
  if (surface == NULL){
    cout << "Failed to load: " << fname << endl;
    return;
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
    offset.x = Application::SCREEN_WIDTH / 2 - surface->w/2;
  }
  if (bitmask & VBOTTOM){
    offset.y = Application::SCREEN_HEIGHT - surface->h;
  }
  if (bitmask & VCENTER){
    offset.y = Application::SCREEN_HEIGHT/2 - surface->h/2;
  }
}

void Sprite::alignTo(Sprite* sprite, unsigned bitmask){
  if (bitmask & HCENTER){
    offset.x = Application::SCREEN_WIDTH / 2 - surface->w/2;
  }
  if (bitmask & VBOTTOM){
    offset.y = Application::SCREEN_HEIGHT - surface->h;
  }
  if (bitmask & VCENTER){
    offset.y = sprite->offset.y + sprite->surface->h/2 - surface->h/2;
  }
}
