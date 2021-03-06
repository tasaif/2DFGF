#include "application.h"
#include "stage.h"

extern Application* app;

Stage::Stage(){
}

Stage::~Stage(){
  while(backgrounds.size() > 0){
    delete backgrounds[0];
    backgrounds.erase(backgrounds.begin());
  }
}

void Stage::push(string fname){
  backgrounds.push_back(new Sprite(fname));
}

void Stage::draw(){
  for(unsigned i=0; i<backgrounds.size(); i++){
    app->drawsys->draw(backgrounds[i]);
  }
}

void Stage::resetPos(){
  Sprite* bg;
  // Start from 1 because 0 is the background
  for(unsigned i=1; i<backgrounds.size(); i++){
    bg = backgrounds[i];
    bg->align(Sprite::HCENTER);
    bg->offset.y = HEIGHT * -1 + Application::SCREEN_HEIGHT;
  }
}

