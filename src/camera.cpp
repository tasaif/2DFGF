#include "camera.h"

Camera::Camera(DrawSystem* _drawsys){
  drawsys = _drawsys;
}

Camera::~Camera(){
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

void Camera::setFocus(SDL_Rect _offset){
  offset = _offset;
}
