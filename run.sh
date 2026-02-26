#!/bin/bash

#g++ main.cpp -o main.out -ldl -lglfw -lglut -lGL
g++ main.cpp -o main.out -lallegro -lalleg -lallegro_color -lallegro_dialog -lallegro_primitives
./main.out