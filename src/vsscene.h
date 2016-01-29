#ifndef VSSCENE_H
#define VSSCENE_H

#include <iostream>
#include <string>
#include <vector>
#include "scene.h"
#include "ltimer.h"
#include "option.h"
#include "button.h"
#include "gamestate.h"
using namespace std;

class VSScene : public Scene {
  private:
    //Option* bgm_option = NULL;
    //sound option_changed;
    //sound option_selected;
    void setup_options();

  public:
    VSScene(CharacterSystem*);
    ~VSScene();

    bool first();
    bool run();
    GameState end();

    //unsigned is the player id 0 or 1
    Character* getCharacter(unsigned);
    Player* getP(unsigned);
};

#endif
