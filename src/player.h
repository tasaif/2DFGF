#ifndef PLAYER_H
#define PLAYER_H

#include "joystick.h"
#include "character.h"
#include "stage.h"
#include "characterindex.h"
#include "playerstates.h"
#include "fight.h"
#include <vector>
using namespace std;

/*
 * NOTE:
 * Player position origin is bottom left of screen 60px up from
 *  the bottom
 * Player sprites are rendered center aligned with the player position
 */

class Character;
class Fight;

class Player {
  private:
    unsigned hpwidth();
    void update_health_bar();
    int pnum = -1;
    HitBox normalize_box(HitBox);
    vector<HitBox> atk_boxes;

  public:
    static const int HPWIDTH = 240;
    static const int HPHEIGHT = 9;
    static const unsigned HPCOLOR = 0xffc71cff;
    /*
     * This position is passed to the camera
     * It is not in normal screen coordinates
     */
    SDL_Rect position;
    CharacterIndex charselect = ciNULL;
    Joystick* joystick = NULL;
    Character* character = NULL;
    Fight* fight = NULL;
    Player* opponent = NULL;
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
    vector<HitBox> getDefBoxes();
    vector<HitBox>* getAtkBoxes();
    void spawnAtkBox(HitBox);
};

#endif
