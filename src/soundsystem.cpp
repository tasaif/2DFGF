#include "soundsystem.h"
#include "boost/filesystem.hpp"
using namespace boost::filesystem;

extern path music_path;

Music::Music(){
  mix_music = NULL;
}

Music::~Music(){
  unload();
}

void Music::load(string fname){
  if (mix_music != NULL){
    unload();
  }
  name = fname;
  mix_music = Mix_LoadMUS((music_path / name).string().c_str());
  if (mix_music == NULL){
    cout << "Error: Failed to load \"" << name << "\"" << endl;
    cout << Mix_GetError() << endl;
    name = "";
  }
}

void Music::unload(){
  if (mix_music != NULL){
    Mix_FreeMusic(mix_music);
    mix_music = NULL;
    name = "";
  }
}

void Music::play(){
  cout << "PLAY THE MUSIC" << endl;
  if (mix_music == NULL){
    cout << "Error: Music::play tried to play a null mix_music" << endl;
  } else {
    SoundSystem::stopMusic();
    if (Mix_PlayMusic(mix_music, -1) == -1){
      cout << "Mix_PlayMusic: " << Mix_GetError() << endl;
    }
  }
}

void SoundSystem::stopMusic(){
  cout << "STOP THE MUSIC" << endl;
  Mix_HaltMusic();
  Mix_RewindMusic();
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

//There's a bug with loading mp3 files just use WAV files
//avconv/ffmpeg are perfect for converting files to wav
void SoundSystem::load(string fname){
  Music* m;
  if (!isLoaded(fname)){
    m = new Music();
    m->load(fname);
    music.push_back(m);
  }
}

bool SoundSystem::isLoaded(string fname){
  for(unsigned i=0; i<music.size(); i++){
    if (*music[i] == fname){
      return true;
    }
  }
  return false;
}

//volume should be 0 to 100
void SoundSystem::setBGMVolume(int volume){
  Mix_VolumeMusic((((float)volume)/100.0)*((float)MIX_MAX_VOLUME));
}
