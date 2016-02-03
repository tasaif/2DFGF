#include "application.h"
#include "fight.h"

Fight::Fight(Player* _p, Player* _opponent){
  p = _p;
  c = p->getCharacter();
  opponent = _opponent;
  if (p->getPnum() == 0){
    p->position.x = -1 * Application::SCREEN_WIDTH / 4;
  } else {
    p->position.x = Application::SCREEN_WIDTH / 4;
  }
  p->position.y = 0;
  currentSprite = c->getBaseAnim(psNEUTRAL)->getSprite();
}

Fight::~Fight(){
}

void Fight::run(){
  away = p->position.x < opponent->position.x ? bLEFT : bRIGHT;
  towards = away == bLEFT ? bRIGHT : bLEFT;
  dir = p->joystick->getDirection();

  switch(state){
    case psMATCHSTARTING:
      state = psNEUTRAL;
      break;
    case psNEUTRAL:
      currentSprite = c->getBaseAnim(psNEUTRAL)->getSprite();
      if (p->joystick->Pressed(bLP)){
        c->getBaseAnim(psWALKF)->animation_speed--;
        cout << c->getBaseAnim(psWALKF)->animation_speed << endl;
      } else if (p->joystick->Pressed(bMP)){
        c->getBaseAnim(psWALKF)->animation_speed++;
        cout << c->getBaseAnim(psWALKF)->animation_speed << endl;
      } else if (p->joystick->Pressed(bHP)){
        c->walkf_speed++;
        cout << c->walkf_speed;
      } else if (p->joystick->Pressed(bHK)){
        c->walkf_speed--;
        cout << c->walkf_speed;
      }
      switch(dir){
        case bUP:
          dy = dy_reset;
          state = psJUMPU;
          break;
        case bLEFT:
          dx = -1 * (away == bLEFT ? c->walkb_speed : c->walkf_speed);
          state = away == bLEFT ? psWALKB : psWALKF;
          break;
        case bRIGHT:
          dx = (away == bRIGHT ? c->walkb_speed : c->walkf_speed);
          state = away == bRIGHT ? psWALKB : psWALKF;
          break;
        case bUPRIGHT:
          dy = dy_reset;
          dx = (away == bRIGHT ? c->jumpb_speed : c->jumpf_speed);
          state = away == bRIGHT ? psJUMPB : psJUMPF;
          break;
        case bUPLEFT:
          dy = dy_reset;
          dx = -1 * (away == bLEFT ? c->jumpb_speed : c->jumpf_speed);
          state = away == bLEFT ? psJUMPB : psJUMPF;
          break;
        default:
          break;
      };
      break;
    case psWALKB:
      p->position.x += dx;
      if (dir != away){
        state = psNEUTRAL;
      }
      break;
    case psWALKF:
      currentSprite = c->getBaseAnim(psWALKF)->getSprite();
      p->position.x += dx;
      if (dir != towards){
        state = psNEUTRAL;
      }
      break;
    case psJUMPU:
      dy += c->jump_acc;
      p->position.y += dy;
      if (p->position.y <= 0){
        p->position.y = 0;
        state = psNEUTRAL;
      }
      break;
    case psJUMPF:
    case psJUMPB:
      p->position.x += dx;
      dy += c->jump_acc;
      p->position.y += dy;
      if (p->position.y <= 0){
        p->position.y = 0;
        state = psNEUTRAL;
      }
      break;
    default:
      break;
  };
}

Sprite* Fight::getSprite(){
  return currentSprite;
}

