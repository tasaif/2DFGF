#include "character.h"

extern path character_path;

Character::Character(){
}

Character::~Character(){
  delete icon;
  delete placard;
  delete placard_name;
}

bool Character::init(string _name, string _placard_font){
  name = _name;
  placard_font = _placard_font;
  std::transform(_name.begin(), _name.end(), _name.begin(), ::tolower);
  load_path = character_path / _name;
  icon = new Sprite(load_path, "icon.png");
  placard = new Sprite(load_path, "placard.png");
  placard_name = new TextSprite();
  placard_name->setFont(placard_font, placard_font_size);
  placard_name->init(name);
}

Sprite* Character::getPlacard(){
  return placard;
}

Sprite* Character::getNamePlacard(){
  return placard_name;
}

Sprite* Character::getIcon(){
  return icon;
}
