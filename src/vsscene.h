#ifndef VSSCENE_H
#define VSSCENE_H

#include <iostream>
#include <string>
#include <vector>
#include "scene.h"
#include "ltimer.h"
#include "option.h"
#include "buttontype.h"
#include "gamestate.h"
#include "stage.h"
#include "vsscenestate.h"
#include "fight.h"
#include "fightsystem.h"
#include "camera.h"
using namespace std;

class FightSystem;

class VSScene : public Scene {
  private:
    //Option* bgm_option = NULL;
    //sound option_changed;
    //sound option_selected;
    void setup_options();
    Stage* stage = NULL;
    Sprite* overlay = NULL;
    TextSprite* time = NULL;
    LTimer timer;
    VSSceneState state = vssNULL;
    unsigned match_length;
    unsigned countdown = 0;
    FightSystem* fightsys;
    Camera* camera;

  public:
    VSScene(CharacterSystem*);
    ~VSScene();

    bool first();
    bool run();
    GameState end();

    //unsigned is the player id 0 or 1
    Character* getCharacter(unsigned);
    Player* getP(unsigned);
    void incHealth(unsigned, unsigned);
};

#endif
