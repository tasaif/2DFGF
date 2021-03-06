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
      new_joystick = new Controller(i);
      joysticks.push_back(new_joystick);
    }
  }
  //number of joysticks used to calculate height of keyboard icon
  new_joystick = new Keyboard(number_of_joysticks);
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

bool InputSystem::Pressed(ButtonType button){
  for (unsigned i=0; i<joysticks.size(); i++){
    if (joysticks[i]->Pressed(button)){
      return true;
    }
  }
  return false;
}

bool InputSystem::Pressed(ButtonType button, Joystick* &joystick){
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

