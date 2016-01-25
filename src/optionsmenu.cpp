#include "menu.h"
#include "application.h"

extern Application* app;

void OptionsMenu::setup_options(){
  bgm_option = createOption(omsBGMVOLUME);
  bgm_option->init("BGM Volume", 20, 125, 150);
  bgm_option->press_func[bUP] = [&](){state = omsQUIT;};
  bgm_option->press_func[bDOWN] = [&](){state = omsSFXVOLUME;};

  sfx_option = createOption(omsSFXVOLUME);
  sfx_option->init("SFX Volume", 20, 125, 175);
  sfx_option->press_func[bUP] = [&](){state = omsBGMVOLUME;};
  sfx_option->press_func[bDOWN] = [&](){state = omsDURATION;};

  duration_option = createOption(omsDURATION);
  duration_option->init("Match Timer", 20, 125, 200);
  duration_option->press_func[bUP] = [&](){state = omsSFXVOLUME;};
  duration_option->press_func[bDOWN] = [&](){state = omsQUIT;};

  quit_option = createOption(omsQUIT);
  quit_option->init("Quit", 20, 125, 225);
  quit_option->press_func[bUP] = [&](){state = omsDURATION;};
  quit_option->press_func[bDOWN] = [&](){state = omsBGMVOLUME;};
  quit_option->press_func[bLK] = [&](){exit_code = gsTITLE;};

  bgm_level->init(to_string(app->optionsys->bgmvolume), 20, 400, 0);
  sfx_level->init(to_string(app->optionsys->sfxvolume), 20, 400, 0);
  duration_level->init(to_string(app->optionsys->match_duration), 20, 400, 0);

  bgm_level->alignTo(bgm_option, Sprite::VCENTER);
  sfx_level->alignTo(sfx_option, Sprite::VCENTER);
  duration_level->alignTo(duration_option, Sprite::VCENTER);
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
  bgm_level = new TextSprite();
  sfx_level = new TextSprite();
  duration_level = new TextSprite();
  indicator->init(">", 20, 100, 150);
  setup_options();
}

OptionsMenu::~OptionsMenu(){
  for(unsigned i=0; i<options.size(); i++){
    delete options[i];
  }
  delete bgm_level;
  delete sfx_level;
  delete duration_level;
  delete background;
}

bool OptionsMenu::first(){
  if (!initialized){
    cout << "OptionsMenu was not initialized" << endl;
    return false;
  }
  timer.start();
  exit_code = gsNULL;
  state = omsBGMVOLUME;
  return true;
}

bool OptionsMenu::run(){
  bool option_interacted = false;
  Option* curop;
  drawsys->draw(background);
  drawsys->draw(indicator);
  drawsys->draw(bgm_level);
  drawsys->draw(sfx_level);
  drawsys->draw(duration_level);
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
