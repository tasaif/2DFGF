#ifndef CHARACTERMENU_H
#define CHARACTERMENU_H

#include <iostream>
#include <string>
#include <vector>
#include "scene.h"
#include "ltimer.h"
#include "option.h"
#include "charactermenustate.h"
#include "button.h"
#include "gamestate.h"
using namespace std;

class CharacterMenu : public Scene {
  private:
    CharacterMenuState state = cmsNULL;
    Sprite* selection_box = NULL;
    Sprite* selection_backing = NULL;
    SDL_Rect p1_name_placard_offset;
    SDL_Rect p2_name_placard_offset;
    //Option* bgm_option = NULL;
    //TextSprite* duration_level = NULL;
    //sound option_changed;
    //sound option_selected;
    void setup_options();

  public:
    CharacterMenu(CharacterSystem*);
    ~CharacterMenu();

    bool first();
    bool run();
    GameState end();
};

#endif
