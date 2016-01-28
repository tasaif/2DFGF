#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include "sprite.h"
#include "textsprite.h"
using namespace std;

class Character {
  private:
    const unsigned placard_font_size = 65;
    string name;
    Sprite* icon;
    Sprite** placard;
    TextSprite** placard_name;
    string placard_font;
    path load_path;
    //sound bgm
    //stage stage

  protected:
    bool init(string, string);

  public:
    Character();
    virtual ~Character();

    Sprite* getPlacard(unsigned);
    Sprite* getNamePlacard(unsigned);
    Sprite* getIcon();
};

#endif