#include "hitbox.h"

HitBox::HitBox(){
}

HitBox::~HitBox(){
}

bool HitBox::overlaps(HitBox rhs){
  //http://articles.leetcode.com/2011/05/determine-if-two-rectangles-overlap.html
  int p1x = x;
  int p1y = y;
  int p2x = x + w;
  int p2y = y + h;
  int p3x = rhs.x;
  int p3y = rhs.y;
  int p4x = p3x + rhs.w;
  int p4y = p3y + rhs.h;
  return !(p2y < p3y || p1y > p4y || p2x < p3x || p1x > p4x);
}
