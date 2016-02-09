#ifndef SPARKSYSTEM_H
#define SPARKSYSTEM_H

#include <vector>
#include "animationsystem.h"
#include "camera.h"
using namespace std;

class Camera;

class Spark {
  public:
    Spark(Animation*, HitBox*, bool);
    ~Spark();
    bool dead;
    bool leftSide;
    Animation* src;
    SDL_Rect offset;
    unsigned frame_number;
    unsigned animation_speed;
    unsigned animation_counter;
    Sprite* getSprite();
};

class SparkSystem {
  private:
    AnimationSystem* animsys;
    Animation* hit_source;
    Animation* block_source;
    void mkSpark(Animation*, HitBox*, bool);
    vector<Spark*> sparks;

  public:
    SparkSystem(AnimationSystem*);
    ~SparkSystem();
    void mkHitSpark(HitBox*, bool);
    void mkGuardSpark(HitBox*, bool);
    void drawWith(Camera*);
};

#endif
