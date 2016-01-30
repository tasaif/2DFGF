#ifndef PLAYER_H
#define PLAYER_H

#include "joystick.h"
#include "character.h"
#include "stage.h"
#include "characterindex.h"

class Player {
  private:
    unsigned hpwidth();
    void update_health_bar();

  public:
    static const int HPWIDTH = 240;
    static const int HPHEIGHT = 9;
    static const unsigned HPCOLOR = 0xffc71cff;
    CharacterIndex charselect = ciNULL;
    Joystick* joystick = NULL;
    Character* character = NULL;
    int hp;
    int maxhp;

    Player();
    ~Player();
    Sprite* getPlacard(unsigned);
    Sprite* getNamePlacard(unsigned);
    Character* getCharacter();
    Stage* getStage();

    void prep();
    Sprite* healthBar;
    void incHealth(int);
};

#endif
