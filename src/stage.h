#ifndef STAGE_H
#define STAGE_H

#include "sprite.h"
#include <string>
#include <vector>
using namespace std;

class Stage {
  protected:
    void push(string);
    //sound bgm

  public:
    static const int FLOOR_HEIGHT = 60;
    static const unsigned WIDTH = 1600;
    static const unsigned HEIGHT = 720;
    // In Camera coordinates
    static const int LEFT_MOST = (int)WIDTH / -2;
    static const int RIGHT_MOST = (int)WIDTH / 2;
    vector<Sprite*> backgrounds;
    Stage();
    virtual ~Stage();
    void draw();
    void resetPos();
};

#endif
