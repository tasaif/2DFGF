#include <unordered_map>
#include "move.h"
#include "joystick.h"
#include "moveparserstate.h"
using namespace std;

extern const string legible_buttons[];
extern const string legible_button_states[];

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
  ButtonState bs = bsNULL;
  ButtonType bt = bNULL;
  MoveParserState mpstate = mpBEGIN;
  int charge_time = 0;
  bool done = false;
  for(unsigned i=0; i<=cmd.length(); i++){
    if (i < cmd.length()){
      token = cmd[i];
    }
    if (done) break;
    switch(mpstate){
      case mpBEGIN:
        if (isdigit(token)){
          mpstate = mpDIR;
        } else if (token == 'D' || token == 'U'){
          mpstate = mpBS;
        } else if (token == 'C'){
          mpstate = mpCHARGE;
        } else if (islower(token)){
          mpstate = mpBUTTON;
        } else {
          cout << "Error at " << i << ": Problem occurred while parsing \"" << cmd << "\"" << endl;
          break;
        }
        i--;
        break;
      case mpBS:
        if (token == 'D'){
          bs = bsPRESSED;
        } else if (token == 'U'){
          bs = bsRELEASED;
        }
        mpstate = mpBEGIN;
        break;
      case mpDIR:
        key += token;
        bt = keyToButtonType(key);
        if (bs == bsNULL){
          bs = bsPRESSED;
        }
        mpstate = mpEND;
        break;
      case mpCHARGE:
        charge_time = 20;
        mpstate = mpBEGIN;
        break;
      case mpBUTTON:
        key += token;
        if (!islower(token)){
          bt = keyToButtonType(key);
          mpstate = mpEND;
        }
        break;
      case mpEND:
        retval.push_back(MoveState(bt, bs, charge_time));
        bt = bNULL;
        bs = bsNULL;
        mpstate = mpBEGIN;
        key = "";
        if (i == cmd.length()){
          done = true;
        }
        i--;
        break;
    };
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
  MoveState* ms;
  for(unsigned i=0; i<command.size(); i++){
    ms = &command[i];
    cout << legible_button_states[ms->state] << legible_buttons[ms->button] << " ";
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

PlayerState Move::getType(){
  return type;
}

int Move::getIndex(){
  return move_number;
}
