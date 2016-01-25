#include "menu.h"
#include "application.h"

extern Application* app;

void Menu::setup_options(){
  start_option = createOption(msNULL);
  start_option->init("Press Start", 25, 0, 300);
  start_option->align(
    Sprite::HCENTER
  );
  start_option->press_func[bSTART] = [&](){state = msVS;};

  vs_option = createOption(msVS);
  vs_option->init("2P Versus", 25, 0, 300);
  vs_option->align(
    Sprite::HCENTER
  );
  vs_option->press_func[bDOWN] = [&](){state = msOPTIONS;};
  vs_option->press_func[bUP] = [&](){state = msQUIT;};

  options_option = createOption(msOPTIONS);
  options_option->init("Options", 25, 0, 325);
  options_option->align(
    Sprite::HCENTER
  );
  options_option->press_func[bDOWN] = [&](){state = msQUIT;};
  options_option->press_func[bUP] = [&](){state = msVS;};

  quit_option = createOption(msQUIT);
  quit_option->init("Quit", 25, 0, 350);
  quit_option->align(
    Sprite::HCENTER
  );
  quit_option->press_func[bDOWN] = [&](){state = msVS;};
  quit_option->press_func[bUP] = [&](){state = msOPTIONS;};
}

Option* Menu::createOption(MenuState _state){
  Option* retval = new Option(_state);
  options.push_back(retval);
  return retval;
}

Menu::Menu(){
  inputsys = app->inputsys;
  drawsys = app->drawsys;
  background = new Sprite();
  setup_options();
}

Menu::~Menu(){
  for(unsigned i=0; i<options.size(); i++){
    delete options[i];
  }
  delete background;
}

bool Menu::first(){
  if (!initialized){
    cout << "Menu was not initialized" << endl;
    return false;
  }
  timer.start();
  return true;
}

bool Menu::run(){
  bool option_interacted = false;
  drawsys->draw(background);
  for(unsigned i=0; i<options.size(); i++){
    Option* curop = options[i];
    if (state == curop->getApplicableState()){
      drawsys->draw(curop);
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
  return true;
}

SceneExitCode Menu::end(){
  return exit_code;
}

bool Menu::init(string fname){
  if(!setBackground(fname)) return false;
  initialized = true;
  return true;
}
