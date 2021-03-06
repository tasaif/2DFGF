#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include "sprite.h"
#include "textsprite.h"
#include "playerstates.h"
#include "animationsystem.h"
#include "movesystem.h"
using namespace std;

class MoveSystem;

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
    void setRotationPoint(Sprite*);

  protected:
    void init(string, string);
    int hp = 100;
    MoveSystem* movesys = NULL;
    string name;
    Animation* base_anim[psEND];
    Animation** norm_anim;
    Animation** spec_anim;

  public:
    Character();
    virtual ~Character();

    int jump_acc = -1;
    int walkf_speed = 4;
    int walkb_speed = 4;
    int jumpf_speed = 8;
    int jumpb_speed = 5;
    int dashb_speed = 4;
    int dashf_speed = 8;

    string getName();
    Sprite* getPlacard(unsigned);
    Sprite* getNamePlacard(unsigned);
    Sprite* getIcon();
    TextSprite* getVSName(unsigned);
    int getHP();
    Animation* getBaseAnim(PlayerState);
    Animation* getNormAnim(unsigned);
    Animation* getSpecAnim(unsigned);
    MoveSystem* getMoveSys();
};

#endif
