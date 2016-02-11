#ifndef OPTION_H
#define OPTION_H

#include "textsprite.h"
#include "menustate.h"
#include "buttontype.h"

class Menu;

class Option : public TextSprite {
  private:
    unsigned applicable_state = msNULL;

  public:
    Option(unsigned);
    ~Option();
    unsigned getApplicableState();

    std::function<void()>* press_func = NULL;
};

#endif
