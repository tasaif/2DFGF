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
  initialized_animation_speed = animation_speed;
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
  if (dont_loop && current_frame == frames.size() - 1){
    return frames[current_frame]->getSprite();
  }
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

Sprite* Animation::currentSprite(){
  return frames[current_frame]->getSprite();
}

bool Animation::loopComplete(){
  return (bool)loop_count || (current_frame == frames.size() - 1);
}

void Animation::reset(){
  animation_counter = 0;
  current_frame = 0;
  loop_count = 0;
  animation_speed = initialized_animation_speed;
}

path Animation::getPath(){
  return custom_path;
}

Frame* Animation::getFrame(unsigned i){
  return frames[i];
}

void Animation::mkDefBox(unsigned start, unsigned end, HitBox box){
  for(unsigned i=start; i<end; i++){
    getFrame(i)->def_boxes.push_back(box);
  }
}

void Animation::mkAtkBox(unsigned frame_number, unsigned life_span, HitBox box, PlayerState type, int damage){
  box.life_span = life_span;
  box.type = type;
  box.damage = damage;
  getFrame(frame_number)->atk_boxes.push_back(box);
}

vector<HitBox>* Animation::currentDefBoxes(){
  return &frames[current_frame]->def_boxes;
}

vector<HitBox>* Animation::currentAtkBoxes(){
  return &frames[current_frame]->atk_boxes;
}

void Animation::setAnimationSpeed(unsigned _speed){
  animation_speed = _speed;
}

void Animation::setDontLoop(bool _dont_loop){
  dont_loop = _dont_loop;
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

HitBox AnimationSystem::mkBox(int x, int y, int w, int h){
  HitBox offset;
  offset.x = x;
  offset.y = y;
  offset.w = w;
  offset.h = h;
  return offset;
}

unsigned Animation::numberOfFrames(){
  return frames.size();
}

