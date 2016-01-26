#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <string>
#include <vector>
#include "scene.h"
#include "ltimer.h"
#include "option.h"
#include "menustate.h"
#include "button.h"
#include "gamestate.h"
using namespace std;

class Menu : public Scene {
  private:
    MenuState state = msNULL;
    Option* start_option = NULL;
    Option* vs_option = NULL;
    Option* options_option = NULL;
    Option* quit_option = NULL;
    //sound option_changed;
    //sound option_selected;
    void setup_options();

  public:
    Menu();
    ~Menu();

    bool first();
    bool run();
    GameState end();

    bool skip_start = false;
};

#endif
