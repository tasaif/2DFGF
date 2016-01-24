#include <iostream>
#include "inputsystem.h"
using namespace std;

InputSystem::InputSystem(){
  switch(SDL_NumJoysticks()){
    default:
    case 2:
      p2 = new Joystick(1);
    case 1:
      p1 = new Joystick(0);
      break;
    case 0:
      cout << "Warning: No joysticks detected." << endl;
      break;
  };
}

InputSystem::~InputSystem(){
}

bool InputSystem::pressed(Button button){
  if (p1 != NULL && p1->lastPressed() == button)
      return true;
  if (p2 != NULL && p2->lastPressed() == button)
      return true;
  return false;
}
