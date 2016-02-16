#include "sprite.h"
#include "application.h"
#include <iomanip>

extern path image_path;
extern Application* app;

void Sprite::init(path _custom_path, string _fname){
  offset.x = 0;
  offset.y = 0;
  custom_path = _custom_path;
  if (_fname != ""){
    load(_fname);
  }
}

Sprite::Sprite(){
  init(path(""), "");
}

Sprite::Sprite(string _fname){
  init(path(""), _fname);
}

Sprite::Sprite(path _custom_path, string _fname){
  init(_custom_path, _fname);
}

Sprite::~Sprite(){
  unload();
}

void Sprite::align(Sprite* _sprite, SDL_Rect& _offset, unsigned bitmask){
  if (bitmask & Sprite::HCENTER){
    _offset.x = Application::SCREEN_WIDTH / 2 - _sprite->getW()/2;
  }
  if (bitmask & Sprite::VBOTTOM){
    _offset.y = Application::SCREEN_HEIGHT - _sprite->getH();
  }
  if (bitmask & Sprite::VCENTER){
    _offset.y = Application::SCREEN_HEIGHT/2 - _sprite->getH()/2;
  }
}

void Sprite::mkRect(unsigned w, unsigned h, Uint32 color){
  unload();
  SDL_Renderer* renderer = app->drawsys->getRenderer();
  SDL_Texture* before = SDL_GetRenderTarget(renderer);
  SDL_SetRenderDrawColor(renderer, (color & 0xff000000) >> 24, (color & 0xff0000) >> 16, (color & 0xff00) >> 8, color & 0xff);
  texture = SDL_CreateTexture(renderer, DrawSystem::FORMAT, SDL_TEXTUREACCESS_TARGET, w, h);
  SDL_SetRenderTarget(renderer, texture);
  SDL_RenderClear(renderer);
  SDL_SetRenderTarget(renderer, before);
}

void Sprite::load(string _fname){
  SDL_Surface* surface;
  SDL_Renderer* renderer = app->drawsys->getRenderer();
  if (custom_path.string() == ""){
    _fname = (image_path / _fname).string();
  } else {
    _fname = (custom_path / _fname).string();
  }
  unload();
  fname = _fname;
  surface = IMG_Load(_fname.c_str());
  if (surface == NULL){
    cout << "Failed to load: " << _fname << endl;
    return;
  }
  texture = SDL_CreateTextureFromSurface(renderer, surface);
  if (texture == NULL){
    cout << "Error: Unable to create texture from \"" << _fname << "\": " << SDL_GetError() << endl;
  }
  SDL_FreeSurface(surface);
}

void Sprite::unload(){
  if (texture != NULL){
    SDL_DestroyTexture(texture);
    texture = NULL;
    fname = "";
  }
}

bool Sprite::valid(){
  if (texture != NULL) return true;
  return false;
}

void Sprite::setPos(int x, int y){
  offset.x = x;
  offset.y = y;
}

void Sprite::align(unsigned bitmask){
  align(this, offset, bitmask);
}

void Sprite::alignTo(Sprite* sprite, unsigned bitmask){
  if (bitmask & HCENTER){
    offset.x = Application::SCREEN_WIDTH / 2 - getW()/2;
  }
  if (bitmask & VBOTTOM){
    offset.y = Application::SCREEN_HEIGHT - getH();
  }
  if (bitmask & VCENTER){
    offset.y = sprite->offset.y + sprite->getH()/2 - getH()/2;
  }
}

void Sprite::alignFromRight(int margin){
  offset.x = Application::SCREEN_WIDTH - getW() - margin;
}

void Sprite::rotate(double _angle){
  if (texture == NULL){
    cout << "Warning: Tried to rotate a null texture" << endl;
    return;
  }
  angle = _angle;
}

Sprite* Sprite::duplicate(){
  SDL_Renderer* renderer = app->drawsys->getRenderer();
  SDL_Texture* before = SDL_GetRenderTarget(renderer);
  Sprite* retval = new Sprite();
  retval->texture = SDL_CreateTexture(renderer, DrawSystem::FORMAT, SDL_TEXTUREACCESS_TARGET, getW(), getH());
  retval->rotate(angle);
  retval->setFlipState(flip_state);
  retval->offset = offset;
  SDL_SetRenderTarget(renderer, texture);
  SDL_RenderCopy(renderer, texture, NULL, NULL);
  SDL_SetRenderTarget(renderer, before);
  return retval;
}

void Sprite::dump(){
  cout << fname << ": " << offset.x << ", " << offset.y << endl;
}

int Sprite::getW(){
  int w;
  int h;
  SDL_QueryTexture(texture, NULL, NULL, &w, &h);
  return w;
}

int Sprite::getH(){
  int w;
  int h;
  SDL_QueryTexture(texture, NULL, NULL, &w, &h);
  return h;
}

double Sprite::getAngle(){
  return angle;
}

void Sprite::setFlipState(SDL_RendererFlip _flip_state){
  flip_state = _flip_state;
}
