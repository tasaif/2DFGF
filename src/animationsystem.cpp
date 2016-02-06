#include "animationsystem.h"

Frame::Frame(Animation* _parent, string fname){
  parent = _parent;
  sprite = new Sprite(parent->getPath(), fname);
}

Frame::~Frame(){
  delete sprite;
}

Sprite* Frame::getSprite(){
  return sprite;
}

Animation::Animation(path _custom_path, unsigned _animation_speed){
  custom_path = _custom_path;
  animation_speed = _animation_speed;
}

Animation::~Animation(){
  while(frames.size()){
    delete frames[0];
    frames.erase(frames.begin());
  }
}

void Animation::addFrame(string fname){
  Frame* frame = new Frame(this, fname);
  frames.push_back(frame);
}

Sprite* Animation::getSprite(){
  animation_counter++;
  if (animation_counter >= animation_speed){
    current_frame++;
    if (current_frame >= frames.size()){
      current_frame = 0;
      loop_count++;
    }
    animation_counter = 0;
  }
  return frames[current_frame]->getSprite();
}

Sprite* Animation::primeSprite(){
  reset();
  return frames[0]->getSprite();
}

bool Animation::loopComplete(){
  return (bool)loop_count;
}

void Animation::reset(){
  animation_counter = 0;
  current_frame = 0;
  loop_count = 0;
}

path Animation::getPath(){
  return custom_path;
}

Frame* Animation::getFrame(unsigned i){
  return frames[i];
}

void Animation::mkDefBox(unsigned start, unsigned end, SDL_Rect box){
  for(unsigned i=0; i<end; i++){
    getFrame(i)->def_boxes.push_back(box);
  }
}

vector<SDL_Rect>* Animation::currentDefBoxes(){
  return &frames[current_frame]->def_boxes;
}

AnimationSystem::AnimationSystem(){
}

AnimationSystem::~AnimationSystem(){
}

bool AnimationSystem::alphabetical_sort(string left, string right){
  for (unsigned i=0; i<left.size() && i<right.size(); i++){
    if (left[i] < right[i]) return true;
  }
  return false;
}

Animation* AnimationSystem::makeAnimation(path folder_path, unsigned animation_speed){
  Animation* retval = new Animation(folder_path, animation_speed);
  directory_iterator files = directory_iterator(folder_path);
  directory_iterator ending = directory_iterator();
  vector<string> file_names;
  for(directory_iterator e = files; e != ending; e++){
    file_names.push_back(e->path().filename().string());
  }
  sort(file_names.begin(), file_names.end(), alphabetical_sort);
  for(unsigned i=0; i<file_names.size(); i++){
    retval->addFrame(file_names[i]);
  }
  return retval;
}

SDL_Rect AnimationSystem::mkBox(int x, int y, int w, int h){
  SDL_Rect offset;
  offset.x = x;
  offset.y = y;
  offset.w = w;
  offset.h = h;
  return offset;
}
