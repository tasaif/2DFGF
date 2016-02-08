#ifndef ANIMATIONSYS_H
#define ANIMATIONSYS_H

#include <iostream>
#include <string>
#include <vector>
#include "boost/filesystem.hpp"
#include "sprite.h"
#include "hitbox.h"
using namespace boost::filesystem;
using namespace std;

class HitBox;
class Animation;

class Frame {
  private:
    Animation* parent;
    Sprite* sprite;

  public:
    Frame(Animation*, string);
    ~Frame();
    Sprite* getSprite();
    vector<HitBox> def_boxes;
    vector<HitBox> atk_boxes;
};

class Animation {
  private:
    vector<Frame*> frames;
    unsigned current_frame = 0;
    path custom_path;
    unsigned animation_counter = 0;
    unsigned loop_count = 0;

  public:
    //Change this to private
    unsigned animation_speed = 10;

    Animation(path, unsigned);
    ~Animation();
    void addFrame(string);
    path getPath();
    Sprite* getSprite();
    Sprite* primeSprite();
    Sprite* currentSprite();
    bool loopComplete();
    void reset();
    Frame* getFrame(unsigned);
    void mkDefBox(unsigned, unsigned, HitBox);
    void mkAtkBox(unsigned, unsigned, HitBox);
    vector<HitBox>* currentDefBoxes();
    vector<HitBox>* currentAtkBoxes();
};

class AnimationSystem {
  private:
    static bool alphabetical_sort(string, string);

  public:
    AnimationSystem();
    ~AnimationSystem();
    Animation* makeAnimation(path, unsigned);
    HitBox mkBox(int, int, int, int);
};

#endif
