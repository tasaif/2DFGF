#include "null.h"

extern path character_path;

NullChar::NullChar(){
  init("NULL", "mode7.ttf");
  hp = 200;
  tmp = new Sprite(character_path, "null/animations/breathing/null-0.png");
  tmp->mkFlipped();
}

NullChar::~NullChar(){
  delete tmp;
}
