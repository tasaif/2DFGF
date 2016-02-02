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
    }
    animation_counter = 0;
  }
  return frames[current_frame]->getSprite();
}

path Animation::getPath(){
  return custom_path;
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
