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
#include "joystick.h"
using namespace std;

class SelectMenu : public Scene {
  private:
    vector<Joystick*> joysticks;
    LTimer timer;
    SelectMenuState state = smsNULL;
    //Option* bgm_option = NULL;
    //TextSprite* bgm_level = NULL;
    //sound controller moved
    void setup_options();

  public:
    SelectMenu();
    ~SelectMenu();

    bool first();
    bool run();
    GameState end();
};

#endif
