#ifndef BILLBOARD_H
#define BILLBOARD_H

#include <iostream>
#include <string>
#include "scene.h"
#include "ltimer.h"
#include "gamestate.h"
using namespace std;

class Billboard : public Scene {
  private:
    LTimer timer;
    unsigned duration = 2000;

  public:
    Billboard(GameState);
    ~Billboard();

    bool first();
    bool run();
    GameState end();
};

#endif
