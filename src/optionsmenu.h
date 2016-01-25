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
    bool initialized = false;
    OptionsMenuState state = omsNULL;
    Option* bgm_option = NULL;
    Option* sfx_option = NULL;
    Option* duration_option = NULL;
    Option* quit_option = NULL;
    TextSprite* indicator = NULL;
    vector<Option*> options;
    //sound option_changed;
    //sound option_selected;
    void setup_options();
    Option* createOption(unsigned);

  public:
    OptionsMenu();
    ~OptionsMenu();

    bool first();
    bool run();
    GameState end();

    bool init(string);
};

#endif
