#ifndef DRAWSYS_H
#define DRAWSYS_H
#include "application.h"

class Application;
class Sprite;

extern Application* app;

class DrawSystem {
  private:
    SDL_Surface* screen;
    Sprite* cross;

  public:
    DrawSystem();
    ~DrawSystem();
    void draw(Sprite*);
    void draw(Sprite*, SDL_Rect);
    SDL_PixelFormat* format();
    void tick(SDL_Rect);
};

#endif
