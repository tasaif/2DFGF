#ifndef GAME_H
#define GAME_H
#include "drawsystem.h"
#include "sprite.h"
#include "scene.h"
#include "billboard.h"

class Application;
class DrawSystem;

extern Application* app;
enum GameState {
  gsNULL,
  gsLOGO,
  gsINTRO,
  gsTITLE,
  gsOPTIONS,
  gsCHARACTERS,
  gsVS,
  gsQUIT
};

class Game {
  private:
    Billboard* logo;
    GameState gamestate = gsNULL;

  public:
    Game();
    ~Game();

    bool run();
};

#endif
