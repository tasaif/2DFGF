#ifndef DRAWSYS_H
#define DRAWSYS_H
#include "application.h"

class Application;
class Sprite;

extern Application* app;

class DrawSystem {
  private:
    SDL_RendererInfo info;
    SDL_Renderer* renderer;
    Sprite* cross;

  public:
    static const Uint32 FORMAT = SDL_PIXELFORMAT_RGBA8888;

    DrawSystem();
    ~DrawSystem();
    void draw(Sprite*);
    void draw(Sprite*, SDL_Rect);
    //SDL_PixelFormat* format();
    void tick(SDL_Rect);
    void fill(unsigned);
    void fill(SDL_Rect, Uint32);
    SDL_Renderer* getRenderer();
};

#endif
