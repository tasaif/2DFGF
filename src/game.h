#ifndef GAME_H
#define GAME_H
#include "drawsystem.h"
#include "sprite.h"
#include "billboard.h"
#include "menu.h"

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
    Menu* title_menu;
    GameState gamestate = gsINTRO;

  public:
    Game();
    ~Game();

    bool run();
};

#endif
