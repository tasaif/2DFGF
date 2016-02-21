#include "soundsystem.h"

Music::Music(){
}

Music::~Music(){
  unload();
}

void Music::load(string fname){
  if (mix_music != NULL){
    unload();
  }
  name = fname;
  mix_music(Mix_LoadMUS(name));
}

void Music::unload(){
  if (mix_music != NULL){
    Mix_FreeMusic(mix_music);
    mix_music = NULL;
    name = "";
  }
}

bool Music::operator ==(const string fname){
  return fname == name;
}

SoundSystem::SoundSystem(){
  if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0){
    cout << "SDL Mixer failed to initialize: " << Mix_GetError() << endl;
  }
}

SoundSystem::~SoundSystem(){
  while (!music.size()){
    delete music[0];
    music.erase(music.begin());
  }
  Mix_Quit();
}

void SoundSystem::load(string fname){
  Music* m;
  if (!isLoaded(fname)){
    m = new Music();
    m->load(fname);
    music.push_back(m);
  }
}

void SoundSystem::isLoaded(string fname){
  for(unsigned i=0; i<musics.size(); i++){
    if (music[i] == fname){
      return true;
    }
  }
}
