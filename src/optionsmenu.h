#ifndef OPTIONSMENU_H
#define OPTIONSMENU_H

#include <iostream>
#include <string>
#include <vector>
#include "scene.h"
#include "ltimer.h"
#include "option.h"
#include "optionsmenustate.h"
#include "button.h"
#include "gamestate.h"
using namespace std;

class OptionsMenu : public Scene {
  private:
    LTimer timer;
    OptionsMenuState state = omsNULL;
    Option* bgm_option = NULL;
    Option* sfx_option = NULL;
    Option* duration_option = NULL;
    Option* quit_option = NULL;
    TextSprite* bgm_level = NULL;
    TextSprite* sfx_level = NULL;
    TextSprite* duration_level = NULL;
    //sound option_changed;
    //sound option_selected;
    void setup_options();

  public:
    OptionsMenu();
    ~OptionsMenu();

    bool first();
    bool run();
    GameState end();
};

#endif
