#ifndef SCENE_H
#define SCENE_H

#include <string>
#include "sprite.h"
#include "gamestate.h"
using namespace std;

class InputSystem;
class DrawSystem;

class Scene {
  protected:
    Sprite* background = NULL;
    InputSystem* inputsys = NULL;
    DrawSystem* drawsys = NULL;
    GameState exit_code = gsNULL;
    //Sound bgm;

  public:
    Scene();
    virtual ~Scene();
    bool setBackground(string);
    virtual bool first(){return false;}
    virtual bool run(){return false;}
    virtual GameState end(){return exit_code;}
};

#endif
