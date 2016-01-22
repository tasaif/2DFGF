#ifndef DRAWSYS_H
#define DRAWSYS_H
#include "application.h"

class Application;
class Sprite;

extern Application* app;

class DrawSystem {
  private:
    SDL_Surface* screen;

  public:
    DrawSystem();
    ~DrawSystem();
    void draw(Sprite*);
    SDL_PixelFormat* format();
};

#endif
