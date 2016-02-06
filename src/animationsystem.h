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
    vector<SDL_Rect> def_boxes;
    vector<SDL_Rect> atk_boxes;
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
    bool loopComplete();
    void reset();
    Frame* getFrame(unsigned);
    void mkDefBox(unsigned, unsigned, SDL_Rect);
    void mkAtkBox(unsigned, unsigned, SDL_Rect);
    vector<SDL_Rect>* currentDefBoxes();
    vector<SDL_Rect>* currentAtkBoxes();
};

class AnimationSystem {
  private:
    static bool alphabetical_sort(string, string);

  public:
    AnimationSystem();
    ~AnimationSystem();
    Animation* makeAnimation(path, unsigned);
    SDL_Rect mkBox(int, int, int, int);
};

#endif
