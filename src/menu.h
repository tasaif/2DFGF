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
    LTimer timer;
    bool initialized = false;
    MenuState state = msNULL;
    Option* start_option = NULL;
    Option* vs_option = NULL;
    Option* options_option = NULL;
    Option* quit_option = NULL;
    vector<Option*> options;
    //sound option_changed;
    //sound option_selected;
    void setup_options();
    Option* createOption(MenuState);

  public:
    Menu();
    ~Menu();

    bool first();
    bool run();
    GameState end();

    bool init(string);
};

#endif
