#ifndef OPTION_H
#define OPTION_H

#include <SDL2/SDL_ttf.h>
#include <string>
#include "sprite.h"
using namespace std;

class Option : public Sprite {
  private:
    string font_name;
    unsigned font_size = 12;
    string text;

  public:
    Option();
    Option(string);
    ~Option();
    void init(string, unsigned, int, int);
    void setFont(string);
    void setFontSize(unsigned);
};

#endif
