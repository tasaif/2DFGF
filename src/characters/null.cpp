#include "../application.h"
#include "null.h"

extern path character_path;
extern Application* app;

NullChar::NullChar(){
  animsys = app->animsys;
  movesys = new MoveSystem();
  init("NULL", "mode7.ttf");
  hp = 200;
  norm_anim = new Animation*[nunEND];
  for(unsigned i=0; i<psEND; i++){
    base_anim[i] = NULL;
  }
  for(unsigned i=0; i<nunEND; i++){
    norm_anim[i] = NULL;
  }
  base_anim[psNEUTRAL] = animsys->makeAnimation(character_path / "null/animations/neutral", 5);
  base_anim[psWALKB] = animsys->makeAnimation(character_path / "null/animations/walkb", 4);
  base_anim[psWALKF] = animsys->makeAnimation(character_path / "null/animations/walkf", 4);
  base_anim[psPRECROUCH] = animsys->makeAnimation(character_path / "null/animations/precrouch", 1);
  base_anim[psCROUCH] = animsys->makeAnimation(character_path / "null/animations/crouch", 5);
  base_anim[psPOSTCROUCH] = animsys->makeAnimation(character_path / "null/animations/postcrouch", 1);
  norm_anim[nunLP] = animsys->makeAnimation(character_path / "null/animations/standinglp", 1);
  /*
   * The following values were found qualitatively
   */
  jump_acc = -4;
  walkf_speed = 6;
  walkb_speed = 3;
  jumpf_speed = 10;
  jumpb_speed = 8;
}

NullChar::~NullChar(){
  delete movesys;
  for(unsigned i=0; i<psEND; i++){
    if (base_anim[i] != NULL){
      delete base_anim[i];
      base_anim[i] = NULL;
    }
  }
}
