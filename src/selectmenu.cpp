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

Option* SelectMenu::createOption(unsigned _state){
  Option* retval = new Option(_state);
  options.push_back(retval);
  return retval;
}

SelectMenu::SelectMenu(){
  inputsys = app->inputsys;
  drawsys = app->drawsys;
  optionsys = app->optionsys;
  background = new Sprite();
  //bgm_level = new TextSprite();
  setup_options();
}

SelectMenu::~SelectMenu(){
  for(unsigned i=0; i<options.size(); i++){
    delete options[i];
  }
  //delete bgm_level;
  delete background;
}

bool SelectMenu::first(){
  if (!initialized){
    cout << "SelectMenu was not initialized" << endl;
    return false;
  }
  timer.start();
  exit_code = gsNULL;
  state = smsNULL;
  return true;
}

bool SelectMenu::run(){
  bool option_interacted = false;
  Option* curop;
  drawsys->draw(background);
  //drawsys->draw(bgm_level);
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
  if (exit_code) return false;
  return true;
}

GameState SelectMenu::end(){
  return exit_code;
}

bool SelectMenu::init(string fname){
  if(!setBackground(fname)) return false;
  initialized = true;
  return true;
}
