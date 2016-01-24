#ifndef TEXTSPRITE_H
#define TEXTSPRITE_H
#include <SDL2/SDL_ttf.h>
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
    void setFont(string, unsigned);
    void init(string, unsigned, int, int);
};

#endif
