#ifndef OPTIONSYSTEM_H
#define OPTIONSYSTEM_H

#include <SDL_mixer.h>

class OptionSystem {
  public:
    OptionSystem();
    ~OptionSystem();

    unsigned bgmvolume = MIX_MAX_VOLUME / 2;
    unsigned sfxvolume = MIX_MAX_VOLUME / 2;
    int match_duration = 99;
};

#endif
