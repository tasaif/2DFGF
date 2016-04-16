# 2DFGF
2D Fighting Game Framework

#Debian
  Packages
    libsdl2-dev libsdl2-image-dev libboost-filesystem-dev libsdl2-ttf-dev libsdl2-mixer-dev libsdl2-gfx-dev

  Library Versions:
    libsdl2-dev             2.0.2+dfsg1-6
    libsdl2-image-dev       2.0.0+dfsg-3+b4
    libboost-filesystem-dev 1.55.0.2
    libsdl2-ttf-dev         2.0.12+dfsg1-2
    libsdl-mixer-dev        2.0.0+dfsg1-5
    libsdl2-gfx-dev         1.0.1+dfsg-1

#El Capitan
  First install Homebrew from http://brew.sh/
  (Note: You will have to install xcode)
  
  Using brew, install the following
  Packages
    sdl2 sdl2_mixer sdl2_image sdl2_gfx sdl2_ttf boost cmake

#Windows
  

#Build instructions:
  Regardless of the platform, care has been taken to make compiling and building across Windows, OSX, and Linux as close to the same as possible. You will need the cmake and make packages installed through your package manager.
  
  cmake CMakeListFile.txt
  make
