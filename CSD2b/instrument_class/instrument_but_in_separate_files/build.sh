#!/bin/bash

g++ -c instrument.cpp
g++ -c main.cpp
g++ -o instrument instrument.o main.o
