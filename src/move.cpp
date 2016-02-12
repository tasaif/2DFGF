#include <unordered_map>
#include "move.h"
using namespace std;

Move::Move(){
}

Move::~Move(){
}

ButtonType Move::strToButtonType(string str){
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

vector<ButtonType> Move::parseCmd(string cmd){
  vector<ButtonType> retval;

  return retval;
}

void Move::init(string _command, Animation* _anim, unsigned _move_number, PlayerState _type){
  command = parseCmd(_command);
  anim = _anim;
  move_number = _move_number;
  type = _type;
}
