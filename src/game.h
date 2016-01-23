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
  gsLOGO1,
  gsLOGO2,
  gsINTRO,
  gsTITLE,
  gsOPTIONS,
  gsCHARACTERS,
  gsVS,
  gsQUIT
};

class Game {
  private:
    Billboard* logo1;
    Billboard* logo2;
    GameState gamestate = gsNULL;

  public:
    Game();
    ~Game();

    bool run();
};

#endif
