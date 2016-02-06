#ifndef HITBOX_H
#define HITBOX_H

#include "SDL.h"

class HitBox : public SDL_Rect {
  public:
    HitBox();
    ~HitBox();
    unsigned life_span = 1;
};

#endif
