#include "menu.h"
#include "selectmenu.h"
#include "application.h"

extern Application* app;

void SelectMenu::setup_options(){
  vector<Joystick*> sticks = inputsys->getJoysticks();
  /*bgm_option = createOption(somsBGMVOLUME);
  bgm_option->init("BGM Volume", 20, 125, 150);
  bgm_option->press_func[bUP] = [&](){state = omsQUIT;};
  bgm_option->press_func[bDOWN] = [&](){state = omsSFXVOLUME;};
  bgm_option->press_func[bLEFT] = [&](){
    optionsys->incBGMVolume(-10);
    bgm_level->init(to_string(app->optionsys->getBGMVolume()));
  };
  bgm_option->press_func[bRIGHT] = [&](){
    optionsys->incBGMVolume(10);
    bgm_level->init(to_string(app->optionsys->getBGMVolume()));
  };*/
}

SelectMenu::SelectMenu(){
  //bgm_level = new TextSprite();
  inputsys = app->inputsys;
  setup_options();
}

SelectMenu::~SelectMenu(){
  for(unsigned i=0; i<options.size(); i++){
    delete options[i];
  }
  //delete bgm_level;
}

bool SelectMenu::first(){
  if (!initialized){
    cout << "SelectMenu was not initialized" << endl;
    return false;
  }
  exit_code = gsNULL;
  state = smsNULL;
  return true;
}

bool SelectMenu::run(){
  Joystick* curjoy;
  joysticks = inputsys->getJoysticks();
  drawsys->draw(background);
  for(unsigned i=0; i<joysticks.size(); i++){
    curjoy = joysticks[i];
    drawsys->draw(curjoy->getIcon());
  }
  if (inputsys->Pressed(bMK)){
    exit_code = gsTITLE;
  }
  if (inputsys->Pressed(bLEFT, curjoy)){
    if (curjoy == inputsys->p2){
      inputsys->clearP(curjoy);
    } else {
      inputsys->setP1(curjoy);
    }
  } else if (inputsys->Pressed(bRIGHT, curjoy)){
    if (curjoy == inputsys->p1){
      inputsys->clearP(curjoy);
    } else {
      inputsys->setP2(curjoy);
    }
  }
  if (exit_code) return false;
  return true;
}

GameState SelectMenu::end(){
  return exit_code;
}
