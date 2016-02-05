#include "charactersystem.h"

CharacterSystem::CharacterSystem(){
  characters = new Character*[NUMBEROFCHARACTERS];
  stages = new Stage*[NUMBEROFCHARACTERS];
  for(unsigned i=0; i<NUMBEROFCHARACTERS; i++){
    characters[i] = NULL;
    stages[i] = NULL;
  }
  for(unsigned i=0; i<8; i++){
    characters[i] = new NullChar();
    stages[i] = new NullStage();
  }
  missing_character = new Sprite("missingcharacter.png");
}

CharacterSystem::~CharacterSystem(){
  for(unsigned i=0; i<NUMBEROFCHARACTERS; i++){
    if (characters[i] != NULL){
      delete characters[i];
      characters[i] = NULL;
    }
  }
  delete[] characters;
  delete missing_character;
}

Character* CharacterSystem::getCharacter(CharacterIndex i){
  return characters[i];
}

Sprite* CharacterSystem::getMissingCharacterIcon(){
  return missing_character;
}

Stage* CharacterSystem::getStage(CharacterIndex i){
  return stages[i];
}

Character* CharacterSystem::mkCharacter(CharacterIndex i){
  // Add each character here
  Character* retval = new NullChar();
  return retval;
}
