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
  SDL_Surface* surface;
  if (font == NULL){
    font = app->fontsys->getFont("linux_libertine/LinLibertine_R.ttf", _font_size);
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
  texture = SDL_CreateTextureFromSurface(app->drawsys->getRenderer(), surface);
  SDL_SetTextureBlendMode(texture, SDL_BLENDMODE_BLEND);
  offset.w = surface->w;
  offset.h = surface->h;
  SDL_FreeSurface(surface);
}

void TextSprite::setDefaultFont(){
  font = app->fontsys->getFont("linux_libertine/LinLibertine_R.ttf", DEFAULTFONTSIZE);
}

void TextSprite::setFont(string font_name){
  font = app->fontsys->getFont(font_name, DEFAULTFONTSIZE);
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

void TextSprite::setColor(SDL_Color _color){
  color = _color;
}
