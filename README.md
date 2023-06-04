# LeetCode-Cpp

1. 开发中...
2. python版本: [https://github.com/Jintao-Huang/LeetCode-Py](https://github.com/Jintao-Huang/LeetCode-Py)



## 文件夹介绍
1. `/.vscode`: vscode配置文件
2. `/src`: 含leetcode, mini stl, ml库
   1. `_alg`: leetcode库的算法实现. leetcode库使用**leetcode**命名空间. 
   2. `_ds`: leetcode库的数据结构实现. 
   3. `_lc`: leetcode库的工具库实现. 
   4. `_mini_stl`: mini_stl库(mini标准库)实现, 使用**mini_stl**命名空间. (适配**c++17**标准). 只是为了学习. 
      1. **没啥实用性**, 大多是标准库的**copy和清理**. (以后会对标准库进行**拓展**)
   5. `_ml`: ml库(机器学习库)实现, 类似于python的numpy实现. 使用**ml**命名空间. 
3. `/answer`: leetcode习题解答. 可以作为examples查看用法. 
4. `/tests`: 测试文件. 可以作为examples查看用法. 
5. `/bin`: 用来生成二进制文件. 


## Run
1. examples: run answer/0001.cpp
    ```bash
    # 使用ubuntu, g++
    bash run.sh answer/0001.cpp
    ```

2. use leetcode库
    ```cpp
    #include <leetcode>
    using namespace leetcode;
    //
    #include <ml>
    using namespace mini_stl;  // or mini_stl::
    using namespace ml;  // or ml::
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