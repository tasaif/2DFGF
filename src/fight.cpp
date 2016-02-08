#include "application.h"
#include "fight.h"

Fight::Fight(Player* _p, Player* _opponent){
  p = _p;
  p->fight = this;
  c = p->getCharacter();
  movesys = c->getMoveSys();
  movesys->init(this);
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
  away = p->position.x < opponent->position.x ? bLEFT : bRIGHT;
  towards = away == bLEFT ? bRIGHT : bLEFT;
  dir = p->joystick->getDirection();
  distance = abs_unsigned(opponent->position.x - p->position.x);

  switch(state){
    case psHURTLIGHT:
      currentAnim = c->getBaseAnim(psHURTLIGHT);
      if (previous_state != psHURTLIGHT){
        currentAnim->reset();
        currentSprite = currentAnim->primeSprite();
      } else if (currentAnim->loopComplete()){
        currentSprite = c->getBaseAnim(psNEUTRAL)->primeSprite();
        state = psNEUTRAL;
      } else {
        currentSprite = currentAnim->getSprite();
      }
      break;
    default:
      break;
  };

  if (movesys->checkForMove()){
    state = movesys->type;
  }

  switch(state){
    case psNORMAL:
      currentAnim = c->getNormAnim(movesys->number);
      if (currentAnim->loopComplete()){
        currentSprite = c->getBaseAnim(psNEUTRAL)->primeSprite();
        state = psNEUTRAL;
      } else {
        currentSprite = c->getNormAnim(movesys->number)->getSprite();
      }
      break;
    case psMATCHSTARTING:
      state = psNEUTRAL;
      break;
    case psNEUTRAL:
      currentAnim = c->getBaseAnim(psNEUTRAL);
      currentSprite = currentAnim->getSprite();
      switch(dir){
        case bUP:
          dy = dy_reset;
          state = psJUMPU;
          break;
        case bLEFT:
          dx = -1 * (away == bLEFT ? c->walkb_speed : c->walkf_speed);
          state = away == bLEFT ? psWALKB : psWALKF;
          currentAnim = c->getBaseAnim(state);
          currentSprite = currentAnim->primeSprite();
          break;
        case bRIGHT:
          dx = (away == bRIGHT ? c->walkb_speed : c->walkf_speed);
          state = away == bRIGHT ? psWALKB : psWALKF;
          currentAnim = c->getBaseAnim(state);
          currentSprite = currentAnim->primeSprite();
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
      currentAnim = c->getBaseAnim(psWALKB);
      currentSprite = currentAnim->getSprite();
      p->position.x += limitCheck(dx);
      if (dir != away){
        state = psNEUTRAL;
        currentAnim = c->getBaseAnim(psNEUTRAL);
        currentSprite = currentAnim->primeSprite();
      }
      break;
    case psWALKF:
      currentAnim = c->getBaseAnim(psWALKF);
      currentSprite = currentAnim->getSprite();
      p->position.x += limitCheck(dx);
      if (dir != towards){
        state = psNEUTRAL;
        currentAnim = c->getBaseAnim(psNEUTRAL);
        currentSprite = currentAnim->primeSprite();
      }
      break;
    case psJUMPU:
      dy += c->jump_acc;
      p->position.y += dy;
      if (p->position.y <= 0){
        p->position.y = 0;
        state = psNEUTRAL;
        currentAnim = c->getBaseAnim(psNEUTRAL);
        currentSprite = currentAnim->primeSprite();
      }
      break;
    case psJUMPF:
      p->position.x += limitCheck(dx);
      dy += c->jump_acc;
      p->position.y += dy;
      if (p->position.y <= 0){
        p->position.y = 0;
        state = psNEUTRAL;
        currentAnim = c->getBaseAnim(psNEUTRAL);
        currentSprite = currentAnim->primeSprite();
      }
      break;
    case psJUMPB:
      p->position.x += limitCheck(dx);
      dy += c->jump_acc;
      p->position.y += dy;
      if (p->position.y <= 0){
        p->position.y = 0;
        state = psNEUTRAL;
        currentAnim = c->getBaseAnim(psNEUTRAL);
        currentSprite = currentAnim->primeSprite();
      }
      break;
    case psPRECROUCH:
      currentAnim = c->getBaseAnim(psPRECROUCH);
      currentSprite = currentAnim->getSprite();
      if (dir != bDOWN && dir != bDOWNLEFT && dir != bDOWNRIGHT){
        state = psPOSTCROUCH;
        currentAnim = c->getBaseAnim(psPOSTCROUCH);
        currentSprite = currentAnim->primeSprite();
      } else if (currentAnim->loopComplete()){
        state = psCROUCH;
        currentAnim = c->getBaseAnim(psCROUCH);
        currentSprite = currentAnim->primeSprite();
      }
      break;
    case psCROUCH:
      currentAnim = c->getBaseAnim(psCROUCH);
      currentSprite = currentAnim->getSprite();
      if (dir != bDOWN && dir != bDOWNLEFT && dir != bDOWNRIGHT){
        state = psPOSTCROUCH;
        currentAnim = c->getBaseAnim(psPOSTCROUCH);
        currentSprite = currentAnim->primeSprite();
      }
      break;
    case psPOSTCROUCH:
      currentAnim = c->getBaseAnim(psPOSTCROUCH);
      currentSprite = currentAnim->getSprite();
      if (currentAnim->loopComplete()){
        state = psNEUTRAL;
        currentAnim = c->getBaseAnim(psNEUTRAL);
        currentSprite = currentAnim->primeSprite();
      }
      break;
    default:
      break;
  };

  //Spawn hitboxes if necessary
  vector<HitBox>* new_atk_boxes;
  if (prevSprite != currentSprite && currentAnim != NULL){
    new_atk_boxes = currentAnim->currentAtkBoxes();
    if (new_atk_boxes){
      for(unsigned i=0; i<new_atk_boxes->size(); i++){
        p->spawnAtkBox((*new_atk_boxes)[i]);
      }
    }
  }

  prevSprite = currentSprite;
  previous_state = state;
}

Sprite* Fight::getSprite(){
  return currentSprite;
}

Animation* Fight::getAnim(){
  return currentAnim;
}

Player* Fight::getP(){
  return p;
}

PlayerState Fight::getState(){
  return state;
}

void Fight::setSprite(Sprite* sprite){
  currentSprite = sprite;
}

// The stun timer actually just sets the animation speed
void Fight::setStunTimer(PlayerState _type, int _stun_timer){
  c->getBaseAnim(psHURTLIGHT)->setAnimationSpeed(_stun_timer);
}

void Fight::hitBy(PlayerState _state){
  state = _state;
}
