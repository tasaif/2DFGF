#ifndef SPARKSYSTEM_H
#define SPARKSYSTEM_H

#include <vector>
#include "animationsystem.h"
#include "camera.h"
using namespace std;

class Camera;

class Spark {
  public:
    Spark(Animation*, HitBox*);
    ~Spark();
    bool dead;
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
    void mkSpark(Animation*, HitBox*);
    vector<Spark*> sparks;

  public:
    SparkSystem(AnimationSystem*);
    ~SparkSystem();
    void mkHitSpark(HitBox*);
    void mkGuardSpark(HitBox*);
    void drawWith(Camera*);
};

#endif
