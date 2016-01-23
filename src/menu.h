#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <string>
#include "scene.h"
#include "ltimer.h"
using namespace std;

class Menu : public Scene {
  private:
    LTimer timer;
    bool initialized = false;

  public:
    Menu();
    ~Menu();

    bool first();
    bool run();
    SceneExitCode end();

    bool init(string);
};

#endif
