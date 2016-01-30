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
#include "stage.h"
#include "vsscenestate.h"
using namespace std;

class VSScene : public Scene {
  private:
    //Option* bgm_option = NULL;
    //sound option_changed;
    //sound option_selected;
    void setup_options();
    Stage* stage = NULL;
    Sprite* overlay = NULL;
    Sprite* tmpplayer1 = NULL;
    Sprite* tmpplayer2 = NULL;
    TextSprite* time = NULL;
    LTimer timer;
    VSSceneState state = vssNULL;
    unsigned match_length;
    unsigned countdown = 0;

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
