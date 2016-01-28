#ifndef GAME_H
#define GAME_H
#include "drawsystem.h"
#include "sprite.h"
#include "billboard.h"
#include "menu.h"
#include "optionsmenu.h"
#include "selectmenu.h"
#include "charactermenu.h"
#include "gamestate.h"
#include "player.h"
#include "charactersystem.h"

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
    CharacterMenu* character_menu;
    GameState gamestate = gsTITLE;

  public:
    Game();
    ~Game();

    CharacterSystem* charsys;
    Player** p = NULL;
    bool run();
};

#endif
