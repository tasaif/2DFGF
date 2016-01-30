#ifndef STAGE_H
#define STAGE_H

#include "sprite.h"
#include <string>
#include <vector>
using namespace std;

class Stage {
  protected:
    vector<Sprite*> backgrounds;
    void push(string);
    //sound bgm

  public:
    const unsigned WIDTH = 1600;
    const unsigned HEIGHT = 720;
    Stage();
    virtual ~Stage();
    void draw();
    void resetPos();
    Sprite* getBG(unsigned);
};

#endif
