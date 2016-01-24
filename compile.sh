#!/bin/bash

g++ -std=c++11 -Wall `/usr/bin/sdl2-config --cflags --libs` -lSDL2_image -lSDL2_ttf -lboost_system -lboost_filesystem -o bin/fighter src/*.cpp
