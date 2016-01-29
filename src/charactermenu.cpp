#include "charactermenu.h"
#include "application.h"

void CharacterMenu::setup_options(){
  /*bgm_option = createOption(omsBGMVOLUME);
  bgm_option->init("BGM Volume", 20, 125, 150);
  bgm_option->press_func[bUP] = [&](){state = omsQUIT;};
  bgm_option->press_func[bDOWN] = [&](){state = omsSFXVOLUME;};
  bgm_option->press_func[bLEFT] = [&](){
    optionsys->incBGMVolume(-10);
    bgm_level->init(to_string(optionsys->getBGMVolume()));
  };
  bgm_option->press_func[bRIGHT] = [&](){
    optionsys->incBGMVolume(10);
    bgm_level->init(to_string(optionsys->getBGMVolume()));
  };

  duration_level->init(to_string(optionsys->getMatchDuration()), 20, 400, 0);
  duration_level->alignTo(duration_option, Sprite::VCENTER);*/
}

void CharacterMenu::updateIconOffset(unsigned player){
  TextSprite* icon = icons[player];
  Player* p = getP(player);
  icon->offset.x = 154 + ((p->charselect%4)*83) + ((83-icon->surface->w*player)*player);
  icon->offset.y = 390 - icon->surface->h + 70*(p->charselect > 3 ? 1 : 0);
}

TextSprite* CharacterMenu::createIcon(unsigned player){
  TextSprite* retval = new TextSprite();
  retval->setFont("mode7.ttf");
  retval->init("P" + std::to_string(player+1), 15);
  return retval;
}

CharacterMenu::CharacterMenu(CharacterSystem* _charsys){
  charsys = _charsys;
  optionsys = app->optionsys;
  selection_backing = new Sprite();
  selection_backing->mkRect(332, 140, 0xCC);
  selection_backing->offset.y = 320;
  selection_backing->align(Sprite::HCENTER);
  selection_box = new Sprite("selectionbox.png");
  selection_box->offset.y = 320;
  selection_box->align(Sprite::HCENTER);
  icons = new TextSprite*[2];
  for(unsigned i=0; i<2; i++){
    icons[i] = createIcon(i);
    updateIconOffset(i);
  }
  setup_options();
}

CharacterMenu::~CharacterMenu(){
  for(unsigned i=0; i<2; i++){
    delete icons[i];
  }
  delete[] icons;
  delete selection_box;
  delete selection_backing;
  //delete duration_level;
}

bool CharacterMenu::first(){
  if (!initialized){
    cout << "CharacterMenu was not initialized" << endl;
    return false;
  }
  exit_code = gsNULL;
  state = cmsNULL;
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
  drawsys->draw(getNamePlacard(0));
  drawsys->draw(getNamePlacard(1));
  drawsys->draw(selection_backing);
  for(unsigned i=0; i<NUMBEROFCHARACTERS; i++){
    curchar = charsys->getCharacter((CharacterIndex)i);
    icon = curchar != NULL ? curchar->getIcon() : charsys->getMissingCharacterIcon();
    offset.x = 154 + 83 * (i % 4);
    offset.y = (i < 4) ? 320 : 390;
    drawsys->draw(icon, &offset);
  }
  drawsys->draw(selection_box);
  for(unsigned i=0; i<options.size(); i++){
    curop = options[i];
    drawsys->draw(curop);
  }
  for(unsigned i=0; i<2; i++){
    drawsys->draw(icons[i]);
  }
  for(unsigned i=0; i<options.size(); i++){
    curop = options[i];
    if (state == curop->getApplicableState()){
      setIndicatorPos(curop);
      for (unsigned button = bNULL; button < bEND; button++){
        if (curop->press_func[button] != NULL && inputsys->Pressed((Button)button)){
          curop->press_func[button]();
          option_interacted = true;
          break;
        }
      }
    }
    if (option_interacted) break;
  }
  if (inputsys->Pressed(bMK)){
    exit_code = gsSELECT;
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
