#include "application.h"
#include "fontsystem.h"

extern path font_path;

Font::Font(string fname, unsigned _ptsize):ptsize(_ptsize){
  sdl_font = TTF_OpenFont((font_path / fname).string().c_str(), ptsize);
  TTF_SetFontStyle(sdl_font, TTF_STYLE_BOLD);
  font_name = fname;
  if(!sdl_font) {
    cout << "TTF_OpenFont: " << TTF_GetError() << endl;
  }
}

Font::~Font(){
  TTF_CloseFont(sdl_font);
}

string Font::getFontName(){
  return font_name;
}

unsigned Font::getFontSize(){
  return ptsize;
}

TTF_Font* Font::getSDLFont(){
  return sdl_font;
}

FontSystem::FontSystem(){
  string font_name = "opensans.ttf";
  default_font = new Font(font_name, DEFAULTFONTSIZE);
  fonts.push_back(default_font);
}

FontSystem::~FontSystem(){
  while(fonts.size() > 0){
    delete fonts[0];
    fonts.erase(fonts.begin());
  }
}

Font* FontSystem::getFont(string font_name){
  return getFont(font_name, DEFAULTFONTSIZE);
}

Font* FontSystem::getFont(string font_name, unsigned ptsize){
  Font* newfont;
  Font* itfont;
  for(unsigned i=0; i<fonts.size(); i++){
    itfont = fonts[i];
    if (itfont->getFontName() == font_name && itfont->getFontSize() == ptsize){
      return fonts[i];
    }
  }
  newfont = new Font(font_name, ptsize);
  fonts.push_back(newfont);
  return newfont;
}
