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
  int min = (int)Stage::LEFT_MOST + (int)Application::SCREEN_WIDTH / 2;
  int max = (int)Stage::RIGHT_MOST - (int)Application::SCREEN_WIDTH / 2;
  if (offset.x < min) offset.x = min;
  if (offset.x > max) offset.x = max;
}

void Camera::draw(Sprite* sprite){
  draw(sprite, sprite->offset);
}

bool Camera::draw(Spark* spark){
  Sprite* sprite = spark->getSprite();
  if (sprite == NULL) return false;
  SDL_Rect repos = spark->offset;
  repos.x = repos.x - offset.x - sprite->surface->w/2;
  repos.y = repos.y - sprite->surface->h/2;
  drawsys->draw(sprite, repos);
  return true;
}

void Camera::draw(Sprite* sprite, SDL_Rect _offset){
  SDL_Rect repos;
  repos.x = _offset.x + Application::SCREEN_WIDTH/2 - sprite->surface->w/2 - offset.x;
  repos.y = (int)Application::SCREEN_HEIGHT - (int)Stage::FLOOR_HEIGHT - sprite->surface->h - _offset.y;
  drawsys->draw(sprite, repos);
}

void Camera::drawBG(){
  SDL_Rect repos;
  Sprite* bg;
  unsigned max = stage->backgrounds.size();
  int xoffset;
  drawsys->fill(0x0);
  for(unsigned i=0; i<max; i++){
    bg = stage->backgrounds[i];
    if (i == max - 1){
      xoffset = offset.x;
    } else {
      xoffset = (int)((float)offset.x * ((float)i / (float)max));
    }
    repos.x = bg->offset.x - xoffset;
    repos.y = bg->offset.y;
    drawsys->draw(stage->backgrounds[i], repos);
  }
}

void Camera::drawBox(HitBox box, Uint32 color){
  box.x = box.x - offset.x;
  drawsys->fill(box, color);
}

void Camera::drawBox(vector<HitBox> boxes, Uint32 color){
  for(unsigned i=0; i<boxes.size(); i++){
    drawBox(boxes[i], color);
  }
}
