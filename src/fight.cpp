#include "application.h"
#include "fight.h"
#include "helper.h"

Fight::Fight(Player* _p, Player* _opponent){
  p = _p;
  p->fight = this;
  c = p->getCharacter();
  movesys = c->getMoveSys();
  movesys->init(this);
  movesys->initCharacterMoves();
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

void Fight::hurtHandler(){
  currentAnim = c->getBaseAnim(state);
  if (previous_state != state){
    currentAnim->reset();
    currentSprite = currentAnim->primeSprite();
  } else if (currentAnim->loopComplete()){
    knockback = 0;
    if (crouching){
      state = psCROUCH;
      currentAnim = c->getBaseAnim(state);
      currentSprite = c->getBaseAnim(state)->primeSprite();
    } else {
      state = psNEUTRAL;
      currentAnim = c->getBaseAnim(state);
      currentSprite = c->getBaseAnim(state)->primeSprite();
    }
  } else {
    currentSprite = currentAnim->getSprite();
  }
}

void Fight::blockHandler(){
  if (block_stun < 0){
    state = state == psBLOCK ? psNEUTRAL : psCROUCH;
    currentAnim = c->getBaseAnim(state);
    currentSprite = currentAnim->primeSprite();
  } else {
    currentSprite = currentAnim->getSprite();
    block_stun--;
  }
}

void Fight::run(){
  away = p->position.x < opponent->position.x ? bLEFT : bRIGHT;
  towards = away == bLEFT ? bRIGHT : bLEFT;
  dir = p->joystick->getDirection();
  distance = abs_unsigned(opponent->position.x - p->position.x);

  switch(state){
    case psDASHB:
    case psDASHF:
      if (currentAnim->loopComplete()){
        state = psNEUTRAL;
        currentAnim = c->getBaseAnim(state);
        currentSprite = c->getBaseAnim(state)->primeSprite();
      } else {
        currentSprite = currentAnim->getSprite();
        if (state == psDASHF){
          moveHorizontally(c->dashf_speed * (away == bRIGHT ? -1 : 1));
        } else {
          moveHorizontally(c->dashb_speed * (away == bRIGHT ? 1 : -1));
        }
      }
      break;
    case psHURTCROUCH:
      knockback = 1;
      hurtHandler();
      break;
    case psHURTHEAVY:
      knockback = 2;
      hurtHandler();
      break;
    case psHURTLIGHT:
      knockback = 1;
      hurtHandler();
      break;
    case psCROUCHBLOCK:
    case psBLOCK:
      knockback = 1;
      blockHandler();
      break;
    case psSPECIAL:
      currentAnim = c->getSpecAnim(movesys->index);
      if (currentAnim->loopComplete()){
        currentSprite = c->getBaseAnim(psNEUTRAL)->primeSprite();
        state = psNEUTRAL;
      } else {
        currentSprite = c->getSpecAnim(movesys->index)->getSprite();
      }
      break;
    case psNORMAL:
      currentAnim = c->getNormAnim(movesys->index);
      if (currentAnim->loopComplete()){
        currentSprite = c->getBaseAnim(psNEUTRAL)->primeSprite();
        state = psNEUTRAL;
      } else {
        currentSprite = c->getNormAnim(movesys->index)->getSprite();
      }
      break;
    case psMATCHSTARTING:
      state = psNEUTRAL;
      break;
    case psNEUTRAL:
      grounded = true;
      currentAnim = c->getBaseAnim(psNEUTRAL);
      currentSprite = currentAnim->getSprite();
      if (movesys->checkForMove()){
        state = movesys->type;
        int index = movesys->index;
        switch(state){
          case psSPECIAL:
            currentAnim = c->getSpecAnim(index);
            currentSprite = c->getSpecAnim(index)->primeSprite();
            break;
          case psNORMAL:
            currentAnim = c->getNormAnim(index);
            currentSprite = c->getNormAnim(index)->primeSprite();
            break;
          default:
            currentAnim = c->getBaseAnim(state);
            currentSprite = c->getBaseAnim(state)->primeSprite();
            break;
        }
      } else {
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
      }
      break;
    case psWALKB:
      currentAnim = c->getBaseAnim(psWALKB);
      currentSprite = currentAnim->getSprite();
      moveHorizontally(dx);
      if (dir != away){
        state = psNEUTRAL;
        currentAnim = c->getBaseAnim(psNEUTRAL);
        currentSprite = currentAnim->primeSprite();
      }
      break;
    case psWALKF:
      currentAnim = c->getBaseAnim(psWALKF);
      currentSprite = currentAnim->getSprite();
      moveHorizontally(dx);
      if (dir != towards){
        state = psNEUTRAL;
        currentAnim = c->getBaseAnim(psNEUTRAL);
        currentSprite = currentAnim->primeSprite();
      }
      break;
    case psJUMPU:
      grounded = false;
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
      grounded = false;
      moveHorizontally(dx);
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
      grounded = false;
      moveHorizontally(dx);
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
      crouching = true;
      currentAnim = c->getBaseAnim(psCROUCH);
      currentSprite = currentAnim->getSprite();
      if (dir != bDOWN && dir != bDOWNLEFT && dir != bDOWNRIGHT){
        state = psPOSTCROUCH;
        currentAnim = c->getBaseAnim(psPOSTCROUCH);
        currentSprite = currentAnim->primeSprite();
      }
      break;
    case psPOSTCROUCH:
      crouching = false;
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

  moveHorizontally(knockback * awayMultiplier());

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
  c->getBaseAnim(_type)->setAnimationSpeed(_stun_timer);
}

void Fight::hitBy(PlayerState _state){
  if (crouching){
    state = psHURTCROUCH;
  } else {
    state = _state;
  }
}

bool Fight::blocking(){
  if (away == bLEFT){
    if (dir == bLEFT || dir == bDOWNLEFT){
      return true;
    }
  } else {
    if (dir == bRIGHT || dir == bDOWNRIGHT){
      return true;
    }
  }
  return false;
}

void Fight::enGarde(HitBox* box){
  block_stun = box->block_stun;
  if (state == psCROUCH){
    state = psCROUCHBLOCK;
    currentAnim = c->getBaseAnim(psCROUCHBLOCK);
  } else {
    state = psBLOCK;
    currentAnim = c->getBaseAnim(psBLOCK);
  }
  currentSprite = currentAnim->primeSprite();
}

bool Fight::getPushed(int _dx){
  return false;
}

int Fight::moveHorizontally(int _dx){
  int peekpos;
  next_step = limitCheck(_dx);
  peekpos = p->position.x + next_step;
  if (grounded && inBetween(p->position.x, opponent->position.x, peekpos)){
    if (opponent->fight->moveHorizontally(_dx) != 0){
      p->position.x += next_step;
    }
  } else {
    p->position.x += next_step;
  }
  return next_step;
}

bool Fight::isRightSide(){
  return p->position.x > opponent->position.x;
}

int Fight::awayMultiplier(){
  return isRightSide() ? 1 : -1;
}
