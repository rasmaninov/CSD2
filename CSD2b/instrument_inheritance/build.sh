#!/bin/bash

g++ -c instrument.cpp
g++ -c main.cpp
g++ -c synth.cpp
g++ -o instrument instrument.o main.o synth.o
