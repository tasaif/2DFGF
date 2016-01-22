#ifndef GAME_H
#define GAME_H
#include "drawsystem.h"
#include "sprite.h"

class Application;
class DrawSystem;

extern Application* app;

class Game {
  private:
    DrawSystem* drawsys;
    Sprite* hello;

  public:
    Game();
    ~Game();

    bool run();
};

#endif
