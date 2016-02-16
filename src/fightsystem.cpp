#include "fightsystem.h"

extern unsigned debugstate;

FightSystem::FightSystem(SparkSystem* _sparksys){
  sparksys = _sparksys;
  shadow = new Sprite("shadow.png");
}

FightSystem::~FightSystem(){
  delete shadow;
}

void FightSystem::init(Player* p1, Player* p2){
  p[0] = p1;
  p[1] = p2;
  f[0] = new Fight(p1, p2);
  f[1] = new Fight(p2, p1);
  p1->opponent = p2;
  p2->opponent = p1;
}

void FightSystem::handleInputs(){
  f[0]->run();
  f[1]->run();
}

void FightSystem::resolveHitBoxes(){
  HitBox* box;
  Player* player;
  Player* opponent;
  vector<HitBox> def_boxes;
  vector<HitBox>* atk_boxes;
  for(unsigned i=0; i<2; i++){
    player = p[i];
    opponent = p[1-i];
    bool leftSide = player->position.x < opponent->position.x;
    atk_boxes = player->getAtkBoxes();
    def_boxes = opponent->getDefBoxes();
    for (int i=atk_boxes->size()-1; i>=0; i--){
      box = &(*atk_boxes)[i];
      box->life_span--;
      if (box->life_span < 0){
        atk_boxes->erase(atk_boxes->begin() + i);
      } else {
        for(unsigned j=0; j<def_boxes.size(); j++){
          if (box->overlaps(def_boxes[j])){
            if (opponent->fight->blocking()){
              sparksys->mkGuardSpark(box, leftSide);
              opponent->fight->enGarde(box);
            } else {
              sparksys->mkHitSpark(box, leftSide);
              opponent->fight->hitBy(box->type);
              opponent->fight->setStunTimer(box->type, box->hit_stun);
              atk_boxes->erase(atk_boxes->begin() + i);
            }
            break;
          }
        }
      }
    }
  }
}

void FightSystem::drawWith(Camera* camera){
  SDL_Rect center;
  Player* player;
  Player* opponent;
  SDL_Rect tmpbox;
  Sprite* curSprite;
  vector<HitBox> def_boxes;
  vector<HitBox> atk_boxes;
  center.x = (p[0]->position.x + p[1]->position.x) / 2;
  center.y = (p[0]->position.y + p[1]->position.y) / 2;
  camera->setFocus(center);
  for(unsigned i=0; i<2; i++){
    shadow->offset.x = p[i]->position.x;
    shadow->offset.y = -10;
    camera->draw(shadow);
  }
  for(unsigned i=0; i<2; i++){
    player = p[i];
    opponent = p[1-i];
    def_boxes = player->getDefBoxes();
    atk_boxes = *player->getAtkBoxes();
    curSprite = f[i]->getSprite();
    if (player->position.x < opponent->position.x){
      curSprite->setFlipState(SDL_FLIP_NONE);
    } else {
      curSprite->setFlipState(SDL_FLIP_HORIZONTAL);
    }
    camera->draw(curSprite, player->position);
  }
  sparksys->drawWith(camera);
  if (debugstate == 1){
    for(unsigned i=0; i<2; i++){
      player = p[i];
      def_boxes = player->getDefBoxes();
      atk_boxes = *player->getAtkBoxes();
      //camera->drawBox(def_boxes, 0x0000ff7f);
      //camera->drawBox(atk_boxes, 0xff00007f);
    }
  }
}
