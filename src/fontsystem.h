#ifndef FONTSYS_H
#define FONTSYS_H

#include <SDL_ttf.h>
#include <string>
#include <vector>
using namespace std;

#define DEFAULTFONTSIZE 12

class Font {
  private:
    unsigned ptsize;
    string font_name;
    TTF_Font* sdl_font = NULL;

  public:
    Font(string, unsigned);
    ~Font();
    string getFontName();
    unsigned getFontSize();
    TTF_Font* getSDLFont();
};

class FontSystem {
  private:
    vector<Font*> fonts;
    Font* default_font = NULL;

  public:
    FontSystem();
    ~FontSystem();
    Font* getFont(string);
    Font* getFont(string, unsigned);
};

#endif
