#include "application.h"
#include "textsprite.h"

extern Application* app;

TextSprite::TextSprite(){
  color = {0, 0, 0};
}

TextSprite::~TextSprite(){
}

void TextSprite::init(string _text){
  if (font == NULL){
    font = app->fontsys->getFont("opensans.ttf", DEFAULTFONTSIZE);
  } else {
    init(_text, font->getFontSize());
  }
}

void TextSprite::init(string _text, unsigned _font_size){
  init(_text, _font_size, offset.x, offset.y);
}

void TextSprite::init(string _text, unsigned _font_size, int x, int y){
  if (font == NULL){
    font = app->fontsys->getFont("opensans.ttf", _font_size);
  } else {
    setFont(font->getFontName(), _font_size);
  }
  text = _text;
  setPos(x, y);
  unload();
  surface = TTF_RenderText_Solid(font->getSDLFont(), text.c_str(), color);
  if (surface == NULL){
    cout << "Failed to create ttf surface" << endl;
  }
}

void TextSprite::setFont(string font_name, unsigned font_size){
  font = app->fontsys->getFont(font_name, font_size);
}
