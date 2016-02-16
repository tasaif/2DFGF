#include "null.h"
#include "../application.h"

extern path character_path;

NullStage::NullStage(){
  for(unsigned i=3; i>=1; i--){
    backgrounds.push_back(new Sprite(character_path / "null/stage", to_string(i) + ".png"));
  }
  resetPos();
}

NullStage::~NullStage(){
}

