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
    CharacterIndex defaultp1character = ciNULL;
    CharacterIndex defaultp2character = ciNULL;
    CharacterMenuState state = cmsNULL;
    Sprite* selection_box = NULL;
    Sprite* selection_backing = NULL;
    TextSprite** icons = NULL;
    //Option* bgm_option = NULL;
    //TextSprite* duration_level = NULL;
    //sound option_changed;
    //sound option_selected;
    void setup_options();
    TextSprite* createIcon(unsigned);
    void updateIconOffset(unsigned player);

  public:
    CharacterMenu(CharacterSystem*);
    ~CharacterMenu();

    bool first();
    bool run();
    GameState end();

    //unsigned is the player id 0 or 1
    Sprite* getPlacard(unsigned);
    Sprite* getNamePlacard(unsigned);
    Character* getCharacter(unsigned);
    Player* getP(unsigned);
};

#endif
