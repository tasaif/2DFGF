#include "option.h"

Option::Option(){
}

Option::Option(string _text):text(_text){
}

Option::~Option(){
}

void Option::init(string _text, unsigned _font_size, int x, int y){
  text = _text;
  setFontSize(_font_size);
  setPos(x, y);
}

void Option::setFont(string _font_name){
  font_name = _font_name;
}

void Option::setFontSize(unsigned _font_size){
  font_size = _font_size;
}

