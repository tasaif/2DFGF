#ifndef ANIMATIONSYS_H
#define ANIMATIONSYS_H

#include <iostream>
#include <string>
#include <vector>
#include "boost/filesystem.hpp"
#include "sprite.h"
using namespace boost::filesystem;
using namespace std;

class Animation;

class Frame {
  private:
    Animation* parent;
    Sprite* sprite;

  public:
    Frame(Animation*, string);
    ~Frame();
    Sprite* getSprite();
};

class Animation {
  private:
    vector<Frame*> frames;
    unsigned current_frame = 0;
    path custom_path;
    unsigned animation_counter = 0;

  public:
    //Change this to private
    unsigned animation_speed = 10;

    Animation(path, unsigned);
    ~Animation();
    void addFrame(string);
    path getPath();
    Sprite* getSprite();
};

class AnimationSystem {
  private:
    static bool alphabetical_sort(string, string);

  public:
    AnimationSystem();
    ~AnimationSystem();
    Animation* makeAnimation(path, unsigned);
};

#endif
