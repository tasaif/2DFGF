#!/bin/bash

g++ -std=c++11 -Wall -lSDL2 -lSDL2_image -lSDL2_ttf -lboost_system -lboost_filesystem -o bin/fighter src/*.cpp
