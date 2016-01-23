#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <string>
#include "scene.h"
#include "ltimer.h"
using namespace std;

enum MenuState {
  msNULL,
  msSTARTED,
  msOPTIONS,
  msVS
};

class Menu : public Scene {
  private:
    LTimer timer;
    bool initialized = false;
    MenuState state = msNULL;
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
