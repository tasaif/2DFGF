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
    Animation** norm_anim;

  public:
    Character();
    virtual ~Character();

    unsigned jump_acc = -4;
    unsigned walkf_speed = 4;
    unsigned walkb_speed = 4;
    unsigned jumpf_speed = 5;
    unsigned jumpb_speed = 5;

    string getName();
    Sprite* getPlacard(unsigned);
    Sprite* getNamePlacard(unsigned);
    Sprite* getIcon();
    TextSprite* getVSName(unsigned);
    int getHP();
    Animation* getBaseAnim(PlayerState);
    Animation* getNormAnim(unsigned);
};

#endif
