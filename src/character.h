#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include "sprite.h"
#include "textsprite.h"
#include "playerstates.h"
#include "animationsystem.h"
using namespace std;

class Character {
  private:
    static const int VSNAMEHEIGHT = 13;
    const unsigned placard_font_size = 65;
    Sprite* icon;
    TextSprite* vsname[2];
    Sprite* placard[2];
    TextSprite* placard_name[2];
    string placard_font;
    path load_path;
    //sound bgm
    //stage stage

  protected:
    bool init(string, string);
    int hp = 100;
    string name;
    Animation* base_anim[psEND];

  public:
    Character();
    virtual ~Character();

    float jump_acc = -3.5;
    float walkf_speed = 4;
    float walkb_speed = 3.6;
    float jumpf_speed = 4.8;
    float jumpb_speed = 4.5;

    string getName();
    Sprite* getPlacard(unsigned);
    Sprite* getNamePlacard(unsigned);
    Sprite* getIcon();
    TextSprite* getVSName(unsigned);
    int getHP();
    Animation* getBaseAnim(PlayerState);
};

#endif
