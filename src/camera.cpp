#include "camera.h"

Camera::Camera(DrawSystem* _drawsys){
  drawsys = _drawsys;
  parallax_factor = 2;
}

Camera::~Camera(){
}

void Camera::setStage(Stage* _stage){
  stage = _stage;
}

void Camera::setFocus(SDL_Rect _offset){
  offset = _offset;
}

void Camera::draw(Sprite* sprite){
  draw(sprite, sprite->offset);
}

void Camera::draw(Sprite* sprite, SDL_Rect _offset){
  SDL_Rect repos;
  repos.x = _offset.x + Application::SCREEN_WIDTH/2 - sprite->surface->w/2 - offset.x;
  repos.y = (int)Application::SCREEN_HEIGHT - (int)VSScene::FLOOR_HEIGHT - sprite->surface->h - _offset.y;
  // + offset.y;
  //repos.x += Application::SCREEN_WIDTH;
  drawsys->draw(sprite, repos);
}

void Camera::drawBG(){
  SDL_Rect repos;
  Sprite* bg;
  unsigned max = stage->backgrounds.size();
  drawsys->fill(0x0);
  for(unsigned i=0; i<max; i++){
    bg = stage->backgrounds[i];
    repos.x = bg->offset.x - (int)((float)offset.x * ((float)i / (float)max));
    repos.y = bg->offset.y;
    drawsys->draw(stage->backgrounds[i], repos);
  }
}
