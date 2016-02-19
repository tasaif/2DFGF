#include "character.h"
#include "helper.h"

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
    delete vsname[i];
  }
}

void Character::init(string _name, string _placard_font){
  name = _name;
  placard_font = _placard_font;
  std::transform(_name.begin(), _name.end(), _name.begin(), ::tolower);
  load_path = character_path / _name;
  icon = new Sprite(load_path, "icon.png");
  for(unsigned i=0; i<2; i++){
    placard[i] = NULL;
    placard_name[i] = NULL;
    vsname[i] = NULL;
  }
  placard[0] = new Sprite(load_path, "placard.png");
  placard[0]->offset.x = 25;
  placard[1] = placard[0]->duplicate();
  placard[1]->setFlipState(SDL_FLIP_HORIZONTAL);
  placard[1]->alignFromRight(25);

  placard_name[0] = new TextSprite();
  placard_name[0]->setFont(placard_font, placard_font_size);
  placard_name[0]->init(name);
  placard_name[1] = placard_name[0]->duplicate();

  placard_name[0]->rotate(90);
  placard_name[1]->rotate(270);
  setRotationPoint(placard_name[0]);
  setRotationPoint(placard_name[1]);
  placard_name[0]->align(Sprite::VCENTER);
  placard_name[1]->align(Sprite::VCENTER);
  placard_name[0]->offset.x = 0;
  placard_name[1]->alignFromRight(0);

  for(unsigned i=0; i<2; i++){
    vsname[i] = new TextSprite();
    vsname[i]->setFont("squares2/Squares Bold Free.otf");
    vsname[i]->setColor({0xff, 0xff, 0xff});
    vsname[i]->init(name, VSNAMEHEIGHT);
  }
  vsname[0]->setPos(55, 44);
  vsname[1]->setPos(0, 44);
  vsname[1]->alignFromRight(55);
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

int Character::getHP(){
  return hp;
}

TextSprite* Character::getVSName(unsigned player){
  return vsname[player];
}

string Character::getName(){
  return name;
}

Animation* Character::getBaseAnim(PlayerState ps){
  return base_anim[ps];
}

Animation* Character::getNormAnim(unsigned number){
  return norm_anim[number];
}

Animation* Character::getSpecAnim(unsigned number){
  return spec_anim[number];
}

MoveSystem* Character::getMoveSys(){
  return movesys;
}

void Character::setRotationPoint(Sprite* pname){
  pname->setRotationPoint(new Point(pname->offset.w/2, 0));
}
