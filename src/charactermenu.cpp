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

CharacterMenu::CharacterMenu(CharacterSystem* _charsys){
  charsys = _charsys;
  optionsys = app->optionsys;
  selection_backing = new Sprite();
  selection_backing->mkRect(332, 140, 0xff7f7f7f);
  selection_box = new Sprite("selectionbox.png");
  selection_box->offset.y = 320;
  selection_box->align(Sprite::HCENTER);
  setup_options();
}

CharacterMenu::~CharacterMenu(){
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
  drawsys->draw(background);
  drawsys->draw(selection_backing);
  drawsys->draw(selection_box);
  for(unsigned i=0; i<options.size(); i++){
    curop = options[i];
    drawsys->draw(curop);
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
