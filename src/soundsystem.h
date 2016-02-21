#ifndef SOUNDSYS_H
#define SOUNDSYS_H

#include <iostream>
#include <string>
#include <vector>
#include <SDL_mixer.h>
using namespace std;

class Music {
  private:
    string name;
    Mix_Music mix_music;

  public:
    Music();
    ~Music();
    void load(string);
    void unload();
    bool operator ==(const string);
};

class SoundSystem {
  private:
    vector<Music*> music;

  public:
    SoundSystem();
    ~SoundSystem();
    void load(string);
    bool isLoaded(string);
};

#endif
