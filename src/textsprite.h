#ifndef TEXTSPRITE_H
#define TEXTSPRITE_H
#include <SDL_ttf.h>
#include "sprite.h"
#include "fontsystem.h"

class TextSprite : public Sprite {
  private:
    Font* font = NULL;
    string text;
    SDL_Color color;

  public:
    TextSprite();
    ~TextSprite();
    void setDefaultFont();
    void setFont(string);
    void setFont(string, unsigned);
    void init();
    void init(string);
    void init(string, unsigned);
    void init(string, unsigned, int, int);
    TextSprite* duplicate();
};

#endif
