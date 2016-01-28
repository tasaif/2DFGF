#include "character.h"

extern path character_path;

Character::Character(){
}

Character::~Character(){
  delete icon;
  for(unsigned i=0; i<2; i++){
    if (placard[i] != NULL){
      delete placard[i];
      placard[i] = NULL;
    }
    if (placard_name[i] != NULL){
      delete placard_name[i];
      placard_name[i] = NULL;
    }
  }
  delete[] placard;
  delete[] placard_name;
}

bool Character::init(string _name, string _placard_font){
  name = _name;
  placard_font = _placard_font;
  std::transform(_name.begin(), _name.end(), _name.begin(), ::tolower);
  load_path = character_path / _name;
  icon = new Sprite(load_path, "icon.png");
  placard = new Sprite*[2];
  placard_name = new TextSprite*[2];
  for(unsigned i=0; i<2; i++){
    placard[i] = NULL;
    placard_name[i] = NULL;
  }
  placard[0] = new Sprite(load_path, "placard.png");
  placard[0]->offset.x = 25;
  placard[1] = placard[0]->duplicate();
  placard[1]->flipHorizontal();
  placard[1]->alignFromRight(25);
  placard_name[0] = new TextSprite();
  placard_name[0]->setFont(placard_font, placard_font_size);
  placard_name[0]->init(name);
  placard_name[0]->rotate(90);
  placard_name[1] = placard_name[0]->duplicate();
}

Sprite* Character::getPlacard(unsigned player){
  return placard[player];
}

Sprite* Character::getNamePlacard(unsigned player){
  return placard_name[player];
}

Sprite* Character::getIcon(){
  return icon;
}
