# LeetCode-Cpp
开发中...

## 文件夹介绍
1. `/.vscode`: vscode配置文件
2. `/src`: 含leetcode, mini stl, ml库
   1. `_alg`: leetcode库的算法实现. leetcode库使用leetcode命名空间. 
   2. `_ds`: leetcode库的数据结构实现. 
   3. `_lc`: leetcode库的工具库实现. 
   4. `_mini_stl`: mini_stl库(mini标准库)实现, 使用mini_stl命名空间. (适配c++17标准)
   5. `_ml`: ml库(机器学习库)实现, 类似于python的numpy实现. 使用ml命名空间. 
3. `/answer`: leetcode习题解答. 可以作为examples查看用法. 
4. `/tests`: 测试文件. 可以作为examples查看用法. 
5. `/bin`: 用来生成二进制文件. 


## Run
1. examples: run answer/0001.cpp
    ```bash
    # 使用ubuntu, g++
    bash run.sh
    ```

2. use leetcode库
    ```cpp
    #include <leetcode>
    using namespace leetcode;
    ```


## 性能
1. 100%: 1, 20, 21, 94, 102
2. 95%: 167, 704, 875
3. 85%: 
4. 60%: 
5. 其他: 


## Env
1. ubuntu
2. g++ (需要支持c++17标准)
3. python>=3.8