#include "application.h"
#include "textsprite.h"

extern Application* app;

TextSprite::TextSprite(){
  color = {0, 0, 0};
}

TextSprite::~TextSprite(){
}

void TextSprite::init(){
  init(text);
}

void TextSprite::init(string _text){
  if (font == NULL){
    setDefaultFont();
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
  surface = TTF_RenderUTF8_Blended(font->getSDLFont(), text.c_str(), color);
  if (surface == NULL){
    cout << "Failed to create ttf surface" << endl;
  }
}

void TextSprite::setDefaultFont(){
  font = app->fontsys->getFont("opensans.ttf", DEFAULTFONTSIZE);
}

void TextSprite::setFont(string font_name){
  if (font == NULL){
    setDefaultFont();
  } else {
    font = app->fontsys->getFont("opensans.ttf", DEFAULTFONTSIZE);
  }
}

void TextSprite::setFont(string font_name, unsigned font_size){
  font = app->fontsys->getFont(font_name, font_size);
}

TextSprite* TextSprite::duplicate(){
  TextSprite* retval = new TextSprite();
  retval->setFont(font->getFontName());
  retval->init(text, font->getFontSize(), offset.x, offset.y);
  return retval;
}
