#ifndef PLAYER_H
#define PLAYER_H

#include "joystick.h"
#include "character.h"
#include "stage.h"
#include "characterindex.h"
#include "playerstates.h"

/*
 * NOTE:
 * Player position origin is bottom left of screen 60px up from
 *  the bottom
 * Player sprites are rendered center aligned with the player position
 */

class Player {
  private:
    unsigned hpwidth();
    void update_health_bar();
    int pnum = -1;

  public:
    static const int HPWIDTH = 240;
    static const int HPHEIGHT = 9;
    static const unsigned HPCOLOR = 0xffc71cff;
    SDL_Rect position;
    CharacterIndex charselect = ciNULL;
    Joystick* joystick = NULL;
    Character* character = NULL;
    int hp;
    int maxhp;
    int getPnum();

    Player();
    ~Player();
    Sprite* getPlacard(unsigned);
    Sprite* getNamePlacard(unsigned);
    Character* getCharacter();
    Stage* getStage();

    void prep();
    Sprite* healthBar;
    void incHealth(int);
    void setP(int);
};

#endif
