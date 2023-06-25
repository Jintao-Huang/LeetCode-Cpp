#!/bin/bash
# 请进入LeetCode-Cpp文件夹. 
mkdir -p bin
fpath=$1
folder=${fpath%/*}
fname=${fpath##*/}
fname_no_ext=${fname%.*}
# -fsanitize=address 开启内存错误检测
g++ -std=c++17 -fsanitize=address -fdiagnostics-color=always -g ${folder}/${fname} -o bin/${fname_no_ext} -I src
bin/${fname_no_ext}