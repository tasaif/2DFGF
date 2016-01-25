#include "menu.h"
#include "application.h"

extern Application* app;

void OptionsMenu::setup_options(){
  bgm_option = createOption(omsBGMVOLUME);
  bgm_option->init("BGM Volume", 20, 125, 150);
  bgm_option->press_func[bDOWN] = [&](){state = omsSFXVOLUME;};

  sfx_option = createOption(omsSFXVOLUME);
  sfx_option->init("SFX Volume", 20, 125, 175);
  sfx_option->press_func[bDOWN] = [&](){state = omsDURATION;};

  duration_option = createOption(omsDURATION);
  duration_option->init("Match Timer", 20, 125, 200);
  duration_option->press_func[bDOWN] = [&](){state = omsQUIT;};

  quit_option = createOption(omsQUIT);
  quit_option->init("Quit", 20, 125, 225);
  quit_option->press_func[bDOWN] = [&](){state = omsBGMVOLUME;};
  quit_option->press_func[bLK] = [&](){exit_code = gsTITLE;};
}

Option* OptionsMenu::createOption(unsigned _state){
  Option* retval = new Option(_state);
  options.push_back(retval);
  return retval;
}

OptionsMenu::OptionsMenu(){
  inputsys = app->inputsys;
  drawsys = app->drawsys;
  background = new Sprite();
  indicator->init(">", 20, 100, 150);
  setup_options();
}

OptionsMenu::~OptionsMenu(){
  for(unsigned i=0; i<options.size(); i++){
    delete options[i];
  }
  delete background;
}

bool OptionsMenu::first(){
  if (!initialized){
    cout << "OptionsMenu was not initialized" << endl;
    return false;
  }
  timer.start();
  exit_code = gsNULL;
  state = omsQUIT;
  return true;
}

bool OptionsMenu::run(){
  bool option_interacted = false;
  Option* curop;
  drawsys->draw(background);
  drawsys->draw(indicator);
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

GameState OptionsMenu::end(){
  return exit_code;
}

bool OptionsMenu::init(string fname){
  if(!setBackground(fname)) return false;
  initialized = true;
  return true;
}
