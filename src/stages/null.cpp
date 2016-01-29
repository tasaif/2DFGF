#include "null.h"
#include "../application.h"

extern path character_path;

NullStage::NullStage(){
  Sprite* back = new Sprite();
  back->mkRect(Application::SCREEN_WIDTH, Application::SCREEN_HEIGHT, 0x464646ff);
  backgrounds.push_back(back);
  for(unsigned i=3; i>0; i--){
    backgrounds.push_back(new Sprite(character_path / "null/stage", to_string(i) + ".png"));
  }
  resetPos();
}

NullStage::~NullStage(){
}

