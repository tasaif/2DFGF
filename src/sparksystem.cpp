#include "sparksystem.h"

extern path image_path;

Spark::Spark(Animation* _src, HitBox* box, bool _leftSide){
  src = _src;
  offset = *box;
  leftSide = _leftSide;
  frame_number = 0;
  dead = false;
  animation_speed = 1;
  animation_counter = 0;
  if (leftSide){
    offset.x += offset.w;
  }
}

Spark::~Spark(){
}

Sprite* Spark::getSprite(){
  Sprite* retval;
  if (frame_number >= src->numberOfFrames()){
    return NULL;
  }
  retval = src->getFrame(frame_number)->getSprite();
  animation_counter++;
  if (animation_counter >= animation_speed){
    animation_counter = 0;
    frame_number++;
  }
  return retval;
}

SparkSystem::SparkSystem(AnimationSystem* _animsys){
  animsys = _animsys;
  hit_source = animsys->makeAnimation(image_path / "hitspark", 3);
  block_source = animsys->makeAnimation(image_path / "blockspark", 3);
}

SparkSystem::~SparkSystem(){
}

void SparkSystem::mkSpark(Animation* src, HitBox* box, bool leftSide){
  sparks.push_back(new Spark(src, box, leftSide));
}

void SparkSystem::mkGuardSpark(HitBox* box, bool leftSide){
  mkSpark(block_source, box, leftSide);
}

void SparkSystem::mkHitSpark(HitBox* box, bool leftSide){
  mkSpark(hit_source, box, leftSide);
}

void SparkSystem::drawWith(Camera* cam){
  Spark* spark;
  for(int i=sparks.size()-1; i >= 0; i--){
    spark = sparks[i];
    if (!cam->draw(spark)){
      delete spark;
      sparks.erase(sparks.begin() + i);
      continue;
    }
  }
}
