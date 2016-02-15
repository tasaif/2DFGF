#include <unordered_map>
#include "move.h"
#include "joystick.h"
using namespace std;

extern const string legible_buttons[];

Move::Move(){
}

Move::~Move(){
}

ButtonType Move::keyToButtonType(string str){
  static unordered_map<string, ButtonType> mapping {
    {"1", bDOWNLEFT},
    {"2", bDOWN},
    {"3", bDOWNRIGHT},
    {"4", bLEFT},
    {"6", bRIGHT},
    {"7", bUPLEFT},
    {"8", bUP},
    {"9", bUPRIGHT},
    {"lP", bLP},
    {"mP", bMP},
    {"hP", bHP},
    {"lK", bLK},
    {"mK", bMK},
    {"hK", bHK}
  };
  return mapping[str];
}

vector<MoveState> Move::parseCmd(string cmd){
  vector<MoveState> retval;
  string key;
  char token;
  for(unsigned i=0; i<cmd.length(); i++){
    token = cmd[i];
    key = key + token;
    if (key.length() > 1){
      if (!isupper(token)){
        cout << i << ": Error Parsing \"" << cmd << "\"" << endl;
        cout << "Key length is greater than 1 and next character \n\
          is not an uppercase letter" << endl;
      } else {
        retval.push_back(MoveState(keyToButtonType(key), bsNULL));
        key = "";
        continue;
      }
    }
    if (isdigit(token)){
      retval.push_back(MoveState(keyToButtonType(key), bsNULL));
      key = "";
      continue;
    } else if (islower(token)){
      continue;
    }
  }
  return retval;
}

void Move::init(string _command, Animation* _anim, unsigned _move_number, PlayerState _type, string _name){
  name = _name;
  command = parseCmd(_command);
  anim = _anim;
  move_number = _move_number;
  type = _type;
}

void Move::dump(){
  dump(true);
}

void Move::dump(bool newline){
  for(unsigned i=0; i<command.size(); i++){
    cout << legible_buttons[command[i].button] << " ";
  }
  if (newline){
    cout << endl;
  }
}

vector<MoveState>* Move::getCmd(){
  return &command;
}

string Move::getName(){
  return name;
}
