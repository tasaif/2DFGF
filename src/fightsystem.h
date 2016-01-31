#ifndef FIGHTSYS_H
#define FIGHTSYS_H

#include "drawsystem.h"
#include "fight.h"

class FightSystem {
  private:
    Player* p[2];
    Fight* f[2];

  public:
    FightSystem();
    ~FightSystem();

    void init(Player*, Player*);
    void handleInputs();
    void resolveHitBoxes();
    void drawWith(DrawSystem*);
};

#endif
