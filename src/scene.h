#ifndef SCENE_H
#define SCENE_H

#include <string>
#include "sprite.h"
using namespace std;

class InputSystem;
class DrawSystem;

enum SceneExitCode {
  NULL_EXIT_CODE,
  BILLBOARD_DONE,
  TITLE_SCENE,
  OPTIONS_SCENE,
  CHARACTER_SELECT,
  VS_SCENE
};

class Scene {
  protected:
    Sprite* background = NULL;
    InputSystem* inputsys = NULL;
    DrawSystem* drawsys = NULL;
    SceneExitCode exit_code = NULL_EXIT_CODE;
    //Sound bgm;

  public:
    Scene();
    virtual ~Scene();
    bool setBackground(string);
    virtual bool first(){return false;}
    virtual bool run(){return false;}
    virtual SceneExitCode end(){return NULL_EXIT_CODE;}
};

#endif
