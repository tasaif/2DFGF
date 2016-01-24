#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <string>
#include "scene.h"
#include "ltimer.h"
#include "option.h"
using namespace std;

enum MenuState {
  msNULL,
  msVS,
  msOPTIONS,
  msQUIT
};

class Menu : public Scene {
  private:
    LTimer timer;
    bool initialized = false;
    MenuState state = msNULL;
    Option* start_option = NULL;
    Option* vs_option = NULL;
    //sound option_changed;
    //sound option_selected;
    //start button
    //options button
    //vs button

  public:
    Menu();
    ~Menu();

    bool first();
    bool run();
    SceneExitCode end();

    bool init(string);
};

#endif
