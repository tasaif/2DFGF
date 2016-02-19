#ifndef SELECTMENU_H
#define SELECTMENU_H

#include <iostream>
#include <string>
#include <vector>
#include "scene.h"
#include "../vendor/lazyfoo/ltimer.h"
#include "option.h"
#include "selectmenustate.h"
#include "buttontype.h"
#include "gamestate.h"
#include "optionsystem.h"
#include "joystick.h"
using namespace std;

class SelectMenu : public Scene {
  private:
    vector<Joystick*> joysticks;
    //sound controller moved

  public:
    SelectMenu();
    ~SelectMenu();

    bool first();
    bool run();
    GameState end();
};

#endif
