#ifndef HITBOX_H
#define HITBOX_H

#include "SDL.h"

class HitBox : public SDL_Rect {
  public:
    HitBox();
    ~HitBox();
    int life_span = 1;

    bool overlaps(HitBox);
};

#endif
