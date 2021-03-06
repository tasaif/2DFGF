#ifndef GAME_H
#define GAME_H
#include "drawsystem.h"
#include "sprite.h"
#include "billboard.h"
#include "menu.h"
#include "optionsmenu.h"
#include "selectmenu.h"
#include "charactermenu.h"
#include "vsscene.h"
#include "gamestate.h"
#include "player.h"
#include "charactersystem.h"

class Application;
class DrawSystem;

extern Application* app;
extern unsigned debugstate;

class Game {
  private:
    Billboard* logo1;
    Billboard* logo2;
    Menu* title_menu;
    OptionsMenu* options_menu;
    SelectMenu* select_menu;
    CharacterMenu* character_menu;
    VSScene* vs_scene;
    GameState gamestate = gsNULL;
    Player** p = NULL;
    TextSprite* fps_display;
    bool was_initialized = false;

  public:
    Game();
    ~Game();
    void init();

    CharacterSystem* charsys;
    bool run();

    void clearP(Joystick*);
    void setP1(Joystick*);
    void setP2(Joystick*);
    Player* getP(unsigned);
    bool isPlayer(unsigned, Joystick*);
    bool playersReady();
};

#endif
