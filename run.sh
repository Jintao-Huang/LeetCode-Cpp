#!/bin/bash
# 请进入LeetCode-Cpp文件夹. 
mkdir -p bin
relative_fpath="answer/0001.cpp"
folder=${relative_fpath%/*}
fname=${relative_fpath##*/}
fname_no_ext=${fname%.*}
g++ -std=c++17 -fdiagnostics-color=always -g ${folder}/${fname}  -o bin/${fname_no_ext} -I src
bin/${fname_no_ext}