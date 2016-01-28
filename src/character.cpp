#include "character.h"

extern path character_path;

Character::Character(){
}

Character::~Character(){
  delete icon;
  delete placard;
  delete placard_name;
}

bool Character::init(string _name, string _icon, string _placard, string _placard_font){
  name = _name;
  placard_font = _placard_font;
  icon = new Sprite(_icon);
  placard = new Sprite(_placard);
  placard_name = new TextSprite();
  placard_name->setFont(placard_font, placard_font_size);
  placard_name->init(name);
}
