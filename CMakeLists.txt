cmake_minimum_required (VERSION 2.6)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

project (fighter)
include_directories(fighter
  /usr/include/SDL2
)
add_executable(fighter
  src/application.cpp
  src/billboard.cpp
  src/character.cpp
  src/charactermenu.cpp
  src/charactersystem.cpp
  src/drawsystem.cpp
  src/fontsystem.cpp
  src/game.cpp
  src/inputsystem.cpp
  src/joystick.cpp
  src/keyboardjoystick.cpp
  src/ltimer.cpp
  src/main.cpp
  src/menu.cpp
  src/option.cpp
  src/optionsmenu.cpp
  src/optionsystem.cpp
  src/player.cpp
  src/scene.cpp
  src/selectmenu.cpp
  src/sprite.cpp
  src/textsprite.cpp

  src/characters/null.cpp
)
target_link_libraries(fighter
  SDL2
  SDL2_image
  SDL2_ttf
  SDL2_gfx
  boost_system
  boost_filesystem
)
