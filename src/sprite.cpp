#include "sprite.h"
#include "application.h"
#include <iomanip>

extern path image_path;
extern Application* app;

void Sprite::init(path _custom_path, string fname){
  offset.x = 0;
  offset.y = 0;
  custom_path = _custom_path;
  if (fname != ""){
    load(fname);
  }
}

Sprite::Sprite(){
  init(path(""), "");
}

Sprite::Sprite(string fname){
  init(path(""), fname);
}

Sprite::Sprite(path _custom_path, string fname){
  init(_custom_path, fname);
}

Sprite::~Sprite(){
  unload();
}

void Sprite::mkRect(unsigned w, unsigned h, Uint32 color){
  unload();
  surface = SDL_CreateRGBSurface(0, w, h, 32, app->rmask, app->gmask, app->bmask, app->amask);
  SDL_FillRect(surface, NULL, SDL_MapRGBA(surface->format, (color & 0xff000000) >> 24, (color & 0xff0000) >> 16, (color & 0xff00) >> 8, color & 0xff));
}

void Sprite::load(string fname){
  if (custom_path.string() == ""){
    fname = (image_path / fname).string();
  } else {
    fname = (custom_path / fname).string();
  }
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
