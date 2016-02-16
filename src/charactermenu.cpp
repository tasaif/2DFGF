#include "charactermenu.h"
#include "application.h"

void CharacterMenu::updateIconOffset(unsigned player){
  TextSprite* icon = icons[player];
  Player* p = getP(player);
  icon->offset.x = 154 + ((p->charselect%4)*83) + ((83-icon->getW()*player)*player);
  icon->offset.y = 390 - icon->getH() + 70*(p->charselect > 3 ? 1 : 0);
}

TextSprite* CharacterMenu::createIcon(unsigned player){
  TextSprite* retval = new TextSprite();
  retval->setFont("mode7.ttf");
  retval->init("P" + std::to_string(player+1), 15);
  return retval;
}

CharacterMenu::CharacterMenu(CharacterSystem* _charsys){
  cout << "initializing charactermenu" << endl;
  charsys = _charsys;
  optionsys = app->optionsys;
  selection_backing = new Sprite();
  selection_backing->mkRect(332, 140, 0xCC);
  selection_backing->offset.y = 320;
  selection_backing->align(Sprite::HCENTER);
  selection_box = new Sprite("selectionbox.png");
  selection_box->offset.y = 320;
  selection_box->align(Sprite::HCENTER);
  for(unsigned i=0; i<2; i++){
    state[i] = cmsCHOOSING;
    icons[i] = createIcon(i);
    updateIconOffset(i);
  }
  cout << "done" << endl;
}

CharacterMenu::~CharacterMenu(){
  for(unsigned i=0; i<2; i++){
    delete icons[i];
  }
  delete selection_box;
  delete selection_backing;
}

bool CharacterMenu::first(){
  if (!initialized){
    cout << "CharacterMenu was not initialized" << endl;
    return false;
  }
  exit_code = gsNULL;
  state[0] = cmsCHOOSING;
  state[1] = cmsCHOOSING;
  return true;
}

bool CharacterMenu::run(){
  bool option_interacted = false;
  Option* curop;
  Character* curchar;
  Sprite* icon;
  SDL_Rect offset;
  drawsys->draw(background);
  drawsys->draw(getPlacard(0));
  drawsys->draw(getPlacard(1));
  //drawsys->draw(getNamePlacard(0));
  //drawsys->draw(getNamePlacard(1));
  //drawsys->draw(selection_backing);
  /*
  for(unsigned i=0; i<NUMBEROFCHARACTERS; i++){
    curchar = charsys->getCharacter((CharacterIndex)i);
    icon = curchar != NULL ? curchar->getIcon() : charsys->getMissingCharacterIcon();
    offset.x = 154 + 83 * (i % 4);
    offset.y = (i < 4) ? 320 : 390;
    drawsys->draw(icon, offset);
  }
  drawsys->draw(selection_box);
  for(unsigned i=0; i<options.size(); i++){
    curop = options[i];
    drawsys->draw(curop);
  }
  for(unsigned i=0; i<2; i++){
    if (state[i] == cmsCHOOSING){
      drawsys->draw(icons[i]);
    }
  }
  */
  for(unsigned player=0; player<2; player++){
    Player* p = getP(player);
    switch(state[player]){
      case cmsCHOOSING:
        if (p->joystick->Pressed(bMK)){
          exit_code = gsSELECT;
        }
        if (p->joystick->Pressed(bRIGHT)){
          if (p->charselect < NUMBEROFCHARACTERS - 1){
            p->charselect = (CharacterIndex)((unsigned)p->charselect + 1);
            updateIconOffset(player);
          }
        } else if (p->joystick->Pressed(bLEFT)){
          if (p->charselect > 0){
            p->charselect = (CharacterIndex)((unsigned)p->charselect - 1);
            updateIconOffset(player);
          }
        } else if (p->joystick->Pressed(bDOWN)){
          if (p->charselect < 4){
            p->charselect = (CharacterIndex)((unsigned)p->charselect + 4);
            updateIconOffset(player);
          }
        } else if (p->joystick->Pressed(bUP)){
          if (p->charselect > 3){
            p->charselect = (CharacterIndex)((unsigned)p->charselect - 4);
            updateIconOffset(player);
          }
        } else if (p->joystick->Pressed(bLK)){
          state[player] = cmsSELECTED;
        }
        break;
      case cmsSELECTED:
        if (inputsys->Pressed(bMK)){
          state[player] = cmsCHOOSING;
        }
        state[player] = cmsREADY;
        break;
      default:
        break;
    };
  }
  if (state[0] == cmsREADY && state[1] == cmsREADY){
    exit_code = gsVS;
  }
  if (exit_code) return false;
  return true;
}

GameState CharacterMenu::end(){
  return exit_code;
}

Sprite* CharacterMenu::getPlacard(unsigned player){
  return app->game->getP(player)->getPlacard(player);
}

Sprite* CharacterMenu::getNamePlacard(unsigned player){
  return app->game->getP(player)->getNamePlacard(player);
}

Character* CharacterMenu::getCharacter(unsigned player){
  return app->game->getP(player)->getCharacter();
}

Player* CharacterMenu::getP(unsigned player){
  return app->game->getP(player);
}
