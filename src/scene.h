#ifndef SCENE_H
#define SCENE_H

#include <string>
#include "sprite.h"
#include "textsprite.h"
#include "gamestate.h"
#include "option.h"
using namespace std;

class InputSystem;
class DrawSystem;

class Scene {
  protected:
    Sprite* background = NULL;
    InputSystem* inputsys = NULL;
    DrawSystem* drawsys = NULL;
    GameState exit_code = gsNULL;
    TextSprite* indicator = NULL;
    //Sound bgm;

  public:
    Scene();
    virtual ~Scene();
    bool setBackground(string);
    virtual bool first(){return false;}
    virtual bool run(){return false;}
    virtual GameState end(){return exit_code;}
    void setIndicatorPos(Option*);
};

#endif
