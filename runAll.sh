#!/bin/bash
rm CodeFiles/*/*.h.gch
g++ CodeFiles/*/* TestScripts/*.cpp main.cpp
./a.out
