#include <iostream>
#include "inputsystem.h"
#include "application.h"
using namespace std;

extern Application* app;

InputSystem::InputSystem(){
  unsigned number_of_joysticks = SDL_NumJoysticks();
  Joystick* new_joystick;
  if (number_of_joysticks == 0){
    cout << "Warning: No joysticks detected." << endl;
  } else {
    cout << "Found " << number_of_joysticks << " Joysticks" << endl;
    for (unsigned i=0; i<number_of_joysticks; i++){
      new_joystick = new Joystick(i);
      joysticks.push_back(new_joystick);
    }
  }
  new_joystick = new KeyboardJoystick(number_of_joysticks);
  joysticks.push_back(new_joystick);
  //This will grab the inputs regardless if the window has focus
  //SDL_SetHint("SDL_JOYSTICK_ALLOW_BACKGROUND_EVENTS", "1");
}

InputSystem::~InputSystem(){
  while(joysticks.size() > 0){
    delete joysticks[0];
    joysticks.erase(joysticks.begin());
  }
}

void InputSystem::update(){
  for (unsigned i=0; i<joysticks.size(); i++){
    joysticks[i]->update();
  }
}

bool InputSystem::Pressed(Button button){
  for (unsigned i=0; i<joysticks.size(); i++){
    if (joysticks[i]->Pressed(button)){
      return true;
    }
  }
  return false;
}

bool InputSystem::Pressed(Button button, Joystick* &joystick){
  for (unsigned i=0; i<joysticks.size(); i++){
    if (joysticks[i]->Pressed(button)){
      joystick = joysticks[i];
      return true;
    }
  }
  return false;
}

vector<Joystick*> InputSystem::getJoysticks(){
  return joysticks;
}

void InputSystem::clearP(Joystick* joystick){
  if (joystick == NULL){
    return;
  }
  if (p1->joystick == joystick){
    p1->joystick = NULL;
  } else if (p2->joystick == joystick){
    p2->joystick = NULL;
  }
  joystick->getIcon()->align(Sprite::HCENTER);
}

void InputSystem::setP1(Joystick* joystick){
  clearP(p1->joystick);
  p1->joystick = joystick;
  joystick->getIcon()->offset.x = Application::SCREEN_WIDTH / 4 - joystick->getIcon()->surface->w/2;
}

void InputSystem::setP2(Joystick* joystick){
  clearP(p2->joystick);
  p2->joystick = joystick;
  joystick->getIcon()->offset.x = (Application::SCREEN_WIDTH / 4) * 3 - joystick->getIcon()->surface->w/2;
}

