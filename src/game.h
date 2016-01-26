#ifndef GAME_H
#define GAME_H
#include "drawsystem.h"
#include "sprite.h"
#include "billboard.h"
#include "menu.h"
#include "optionsmenu.h"
#include "selectmenu.h"
#include "gamestate.h"

class Application;
class DrawSystem;

extern Application* app;

class Game {
  private:
    Billboard* logo1;
    Billboard* logo2;
    Menu* title_menu;
    OptionsMenu* options_menu;
    SelectMenu* select_menu;
    GameState gamestate = gsNULL;

  public:
    Game();
    ~Game();

    bool run();
};

#endif
