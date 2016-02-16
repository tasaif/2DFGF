#include "../application.h"
#include "null.h"
#include "../moves/null.h"

extern path character_path;
extern Application* app;

NullChar::NullChar(){
  animsys = app->animsys;
  movesys = new NullMoveSystem();
  init("NULL", "mode7.ttf");
  hp = 200;
  norm_anim = new Animation*[nunEND];
  spec_anim = new Animation*[nusEND];
  for(unsigned i=0; i<psEND; i++){
    base_anim[i] = NULL;
  }
  for(unsigned i=0; i<nunEND; i++){
    norm_anim[i] = NULL;
  }
  for(unsigned i=0; i<nusEND; i++){
    spec_anim[i] = NULL;
  }
  // Animation loading
  base_anim[psNEUTRAL] = animsys->makeAnimation(character_path / "null/animations/neutral", 10);
  base_anim[psWALKB] = animsys->makeAnimation(character_path / "null/animations/walkb", 8);
  base_anim[psWALKF] = animsys->makeAnimation(character_path / "null/animations/walkf", 8);
  base_anim[psPRECROUCH] = animsys->makeAnimation(character_path / "null/animations/precrouch", 2);
  base_anim[psCROUCH] = animsys->makeAnimation(character_path / "null/animations/crouch", 10);
  base_anim[psPOSTCROUCH] = animsys->makeAnimation(character_path / "null/animations/postcrouch", 2);
  base_anim[psHURTCROUCH] = animsys->makeAnimation(character_path / "null/animations/crouchhurt", 6);
  base_anim[psHURTLIGHT] = animsys->makeAnimation(character_path / "null/animations/hurtlight", 6);
  base_anim[psHURTHEAVY] = animsys->makeAnimation(character_path / "null/animations/hurtheavy", 6);
  base_anim[psBLOCK] = animsys->makeAnimation(character_path / "null/animations/block", 2);
  base_anim[psBLOCK]->setDontLoop(true);
  base_anim[psCROUCHBLOCK] = animsys->makeAnimation(character_path / "null/animations/crouchblock", 2);
  base_anim[psCROUCHBLOCK]->setDontLoop(true);

  //Normal Animations
  norm_anim[nunLP] = animsys->makeAnimation(character_path / "null/animations/standinglp", 4);
  norm_anim[nunHP] = animsys->makeAnimation(character_path / "null/animations/standinghp", 4);

  //Special Animations
  spec_anim[nusFIREBALL] = animsys->makeAnimation(character_path / "null/animations/moves/fireball", 8);

  //Defense boxes
  base_anim[psNEUTRAL]->mkDefBox(0, 6, animsys->mkBox(62, 6, 26, 43));
  base_anim[psNEUTRAL]->mkDefBox(0, 6, animsys->mkBox(10, 35, 101, 43));
  base_anim[psNEUTRAL]->mkDefBox(0, 6, animsys->mkBox(38, 68, 54, 53));
  base_anim[psNEUTRAL]->mkDefBox(0, 6, animsys->mkBox(6, 131, 104, 87));
  base_anim[psWALKB]->mkDefBox(0, 6, animsys->mkBox(16, 4, 101, 206));
  base_anim[psCROUCH]->mkDefBox(0, 6, animsys->mkBox(16, 4, 101, 206));

  //Attack boxes
  //base_anim[psNEUTRAL]->mkAtkBox(0, 6, animsys->mkBox(85, 170, 45, 20));
  norm_anim[nunLP]->mkAtkBox(1, 2, animsys->mkBox(171, 32, 65, 24), psHURTLIGHT);
  norm_anim[nunHP]->mkAtkBox(4, 3, animsys->mkBox(186, 27, 17, 19), psHURTHEAVY);

  /*
   * The following values were found qualitatively
   */
  jump_acc = -1;
  walkf_speed = 3;
  walkb_speed = 2;
  jumpf_speed = 8;
  jumpb_speed = 7;
}

NullChar::~NullChar(){
  delete movesys;
  for(unsigned i=0; i<psEND; i++){
    if (base_anim[i] != NULL){
      delete base_anim[i];
      base_anim[i] = NULL;
    }
  }
  for(unsigned i=0; i<nunEND; i++){
    if(norm_anim[i] != NULL){
      delete norm_anim[i];
      norm_anim[i] = NULL;
    }
  }
  for(unsigned i=0; i<nusEND; i++){
    if(spec_anim[i] != NULL){
      delete spec_anim[i];
      spec_anim[i] = NULL;
    }
  }
  delete[] norm_anim;
  delete[] spec_anim;
}
