#!/bin/bash

g++ -c synth.cpp
g++ -c main.cpp
g++ -o instrument synth.o main.o
