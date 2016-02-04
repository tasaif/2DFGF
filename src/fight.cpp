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

unsigned abs_unsigned(int n){
  return n < 0 ? n * -1 : n;
}

int Fight::limitCheck(int dx){
  int max_distance = Application::SCREEN_WIDTH;
  int min_value = Stage::LEFT_MOST;
  int max_value = Stage::RIGHT_MOST;
  int newx = p->position.x + dx;
  int new_distance = abs_unsigned(p->position.x + dx - opponent->position.x);
  if (new_distance > max_distance){
    return 0;
  }
  if (newx > max_value){
    return max_value - p->position.x;
  }
  if (newx < min_value){
    return min_value - p->position.x;
  }
  return dx;
}

void Fight::run(){
  Animation* tmpAnim;
  away = p->position.x < opponent->position.x ? bLEFT : bRIGHT;
  towards = away == bLEFT ? bRIGHT : bLEFT;
  dir = p->joystick->getDirection();
  distance = abs_unsigned(opponent->position.x - p->position.x);

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
        case bDOWNLEFT:
        case bDOWNRIGHT:
        case bDOWN:
          state = psPRECROUCH;
          c->getBaseAnim(psPRECROUCH)->reset();
          break;
        default:
          break;
      };
      break;
    case psWALKB:
      p->position.x += limitCheck(dx);
      if (dir != away){
        state = psNEUTRAL;
      }
      break;
    case psWALKF:
      currentSprite = c->getBaseAnim(psWALKF)->getSprite();
      p->position.x += limitCheck(dx);
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
      p->position.x += limitCheck(dx);
      dy += c->jump_acc;
      p->position.y += dy;
      if (p->position.y <= 0){
        p->position.y = 0;
        state = psNEUTRAL;
      }
      break;
    case psJUMPB:
      p->position.x += limitCheck(dx);
      dy += c->jump_acc;
      p->position.y += dy;
      if (p->position.y <= 0){
        p->position.y = 0;
        state = psNEUTRAL;
      }
      break;
    case psPRECROUCH:
      tmpAnim = c->getBaseAnim(psPRECROUCH);
      currentSprite = tmpAnim->getSprite();
      cout << "foo" << endl;
      if (tmpAnim->loopComplete()){
        state = psCROUCH;
        c->getBaseAnim(psCROUCH)->reset();
      }
      break;
    case psCROUCH:
      currentSprite = c->getBaseAnim(psCROUCH)->getSprite();
      if (dir != bDOWN && dir != bDOWNLEFT && dir != bDOWNRIGHT){
        state = psPOSTCROUCH;
        c->getBaseAnim(psPOSTCROUCH)->reset();
      }
      break;
    case psPOSTCROUCH:
      tmpAnim = c->getBaseAnim(psPOSTCROUCH);
      currentSprite = tmpAnim->getSprite();
      if (tmpAnim->loopComplete()){
        state = psNEUTRAL;
        c->getBaseAnim(psNEUTRAL)->reset();
      }
      break;
    default:
      break;
  };
}

Sprite* Fight::getSprite(){
  return currentSprite;
}

