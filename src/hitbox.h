#ifndef HITBOX_H
#define HITBOX_H

#include "SDL.h"
#include "playerstates.h"

class HitBox : public SDL_Rect {
  public:
    HitBox();
    ~HitBox();
    int life_span = 1;
    int hit_stun = 3;
    int damage = 5;
    PlayerState type = psHURTLIGHT;

    bool overlaps(HitBox);
};

#endif
