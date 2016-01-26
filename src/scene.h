#ifndef SCENE_H
#define SCENE_H

#include <string>
#include "sprite.h"
#include "textsprite.h"
#include "gamestate.h"
#include "option.h"
#include "optionsystem.h"
using namespace std;

class InputSystem;
class DrawSystem;

class Scene {
  protected:
    InputSystem* inputsys = NULL;
    DrawSystem* drawsys = NULL;
    OptionSystem* optionsys = NULL;
    GameState exit_code = gsNULL;
    Sprite* background = NULL;
    TextSprite* indicator = NULL;
    vector<Option*> options;
    bool initialized = false;
    //Sound bgm;
    Option* createOption(unsigned);

  public:
    Scene();
    virtual ~Scene();
    bool setBackground(string);
    virtual bool first(){return false;}
    virtual bool run(){return false;}
    virtual GameState end(){return exit_code;}
    void setIndicatorPos(Option*);
    bool init(string);
};

#endif
