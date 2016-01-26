#include "menu.h"
#include "application.h"

extern Application* app;

void Menu::setup_options(){
  start_option = createOption(msNULL);
  start_option->init("Press Start", 20, 0, 300);
  start_option->align(
    Sprite::HCENTER
  );
  setIndicatorPos(start_option);
  start_option->press_func[bSTART] = [&](){state = msVS;};

  vs_option = createOption(msVS);
  vs_option->init("2P Versus", 20, 0, 300);
  vs_option->align(
    Sprite::HCENTER
  );
  vs_option->press_func[bDOWN] = [&](){state = msOPTIONS;};
  vs_option->press_func[bUP] = [&](){state = msQUIT;};
  vs_option->press_func[bLK] = [&](){exit_code = gsSELECT;};

  options_option = createOption(msOPTIONS);
  options_option->init("Options", 20, 0, 325);
  options_option->align(
    Sprite::HCENTER
  );
  options_option->press_func[bDOWN] = [&](){state = msQUIT;};
  options_option->press_func[bUP] = [&](){state = msVS;};
  options_option->press_func[bLK] = [&](){exit_code = gsOPTIONS;};

  quit_option = createOption(msQUIT);
  quit_option->init("Quit", 20, 0, 350);
  quit_option->align(
    Sprite::HCENTER
  );
  quit_option->press_func[bDOWN] = [&](){state = msVS;};
  quit_option->press_func[bUP] = [&](){state = msOPTIONS;};
  quit_option->press_func[bLK] = [&](){exit_code = gsQUIT;};
}

Menu::Menu(){
  inputsys = app->inputsys;
  drawsys = app->drawsys;
  indicator->init(">", 20, 0, 0);
  setup_options();
}

Menu::~Menu(){
  for(unsigned i=0; i<options.size(); i++){
    delete options[i];
  }
}

bool Menu::first(){
  if (!initialized){
    cout << "Menu was not initialized" << endl;
    return false;
  }
  exit_code = gsNULL;
  state = skip_start ? msVS : msNULL;
  return true;
}

bool Menu::run(){
  bool option_interacted = false;
  Option* curop;
  drawsys->draw(background);
  if (state != msNULL){
    drawsys->draw(indicator);
    for(unsigned i=0; i<options.size(); i++){
      curop = options[i];
      if (curop == start_option) continue;
      drawsys->draw(curop);
    }
  } else {
    drawsys->draw(start_option);
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

GameState Menu::end(){
  skip_start = true;
  return exit_code;
}

