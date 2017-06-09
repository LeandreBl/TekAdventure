#!/bin/zsh
make
./tekadventure
mr_clean
pl src/*; pl include/*; pl lib/*; epinorme --nowarn=true src/*.c
