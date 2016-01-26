#ifndef SELECTMENU_H
#define SELECTMENU_H

#include <iostream>
#include <string>
#include <vector>
#include "scene.h"
#include "ltimer.h"
#include "option.h"
#include "selectmenustate.h"
#include "button.h"
#include "gamestate.h"
#include "optionsystem.h"
using namespace std;

class SelectMenu : public Scene {
  private:
    LTimer timer;
    bool initialized = false;
    OptionSystem* optionsys;
    SelectMenuState state = smsNULL;
    //Option* bgm_option = NULL;
    //TextSprite* bgm_level = NULL;
    vector<Option*> options;
    //sound controller moved
    void setup_options();
    Option* createOption(unsigned);

  public:
    SelectMenu();
    ~SelectMenu();

    bool first();
    bool run();
    GameState end();

    bool init(string);
};

#endif
