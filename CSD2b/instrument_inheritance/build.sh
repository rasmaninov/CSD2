#!/bin/bash

g++ -c instrument.cpp
g++ -c synth.cpp
g++ -c Piano.cpp
g++ -c Guitar.cpp
g++ -c main.cpp
g++ -o instrument instrument.o  synth.o Piano.o Guitar.o main.o
