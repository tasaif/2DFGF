#ifndef OPTION_H
#define OPTION_H

#include "textsprite.h"
#include "menustate.h"
#include "button.h"

class Menu;

class Option : public TextSprite {
  private:
    MenuState applicable_state = msNULL;

  public:
    Option(MenuState);
    ~Option();
    MenuState getApplicableState();

    std::function<void()>* press_func = NULL;
};

#endif
