#ifndef FIGHTSYS_H
#define FIGHTSYS_H

#include "drawsystem.h"
#include "fight.h"
#include "camera.h"

class Camera;

class FightSystem {
  private:
    Player* p[2];
    Fight* f[2];
    Sprite* shadow;

  public:
    FightSystem();
    ~FightSystem();

    void init(Player*, Player*);
    void handleInputs();
    void resolveHitBoxes();
    void drawWith(Camera*);
};

#endif
