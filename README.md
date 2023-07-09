# LeetCode-Cpp

1. 开发中...
   1. 以后算法库实现将使用c++. 
   2. python版本将被废弃, 并将c++实现的算法库用cython包装给python调用. 
   3. 将在9月之前出v0.0.1版本. 
2. python版本: [https://github.com/Jintao-Huang/LeetCode-Py](https://github.com/Jintao-Huang/LeetCode-Py)



## 文件夹介绍
1. `/.vscode`: vscode配置文件
2. `/src`: 含leetcode, mini stl, ml库
   1. `_alg`: **leetcode库**的算法实现. leetcode库使用**leetcode**命名空间. ()
      1. `_array.h`, `_bisect.h`, `_bst.h`, `_dp.h`, `_heap.h`, `_list.h`, `_search.h`, `_sort.h`, `_tree.h`
   2. `_ds`: leetcode库的数据结构实现. 
      1. `_union_find.h`: UnionFind
   3. `_lc`: leetcode库的工具库实现. 
      1. `_lc_ds.h`: MemoManager, ListNode, TreeNode
      2. `_lc_io.h`: operator<<
      3. `_lc_tools`: to_list, from_list, to_tree, from_tree
   4. `_mini_stl`: **mini_stl库**(mini标准库)实现, 使用**mini_stl**命名空间. (适配**c++17**标准). 只是为了学习. 以后会对标准库进行**拓展**
      1. `_algorithm.h`: partial_sum, copy, count_if, count, merge, partition, adjacent_find, unique, iter_swap, reverse, min_element, make_heap, pop_heap, push_heap, partial_sort 
      2. `_functional.h`: plus, multiplies, less, equal_to, less_equal
      3. `_iterator.h`: _iterator_category
      4. `_numeric.h`: accumulate
      5. `_utility.h`: move, forward
   5. `_ml`: **ml库**(机器学习库)实现, 类似于python的numpy实现. 使用**ml**命名空间. 
      1. `_np.h`: sum, mean, max, min, var, std
      2. `_utils`: default_timer, StatData, stat_array, test_time
   6. `.`: common文件
      1. `_io,h`: print, println, operator<<
      2. `_utils.h`: malloc_c, realloc_c, memset_c, memcpy_c, memmove_c
      3. `_types.h`: 一些库的导入. 
      4. `_cxx2a.h`: **c++17以上**版本实现的一些函数和类实现.
         1. sort_heap
      5. `_java`: java语言中的一些算法. (一些算法源码转为c++)
3. `/answer`: **leetcode习题解答**. 可以作为examples查看用法. 
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
    #include <leetcode>  // 不导入mini_stl和ml
    using namespace leetcode;
    //
    #include <ml>  // 会导入src中所有内容
    using namespace leetcode;  // or leetcode::
    using namespace mini_stl;  // or mini_stl::
    using namespace ml;  // or ml::
    ```


## 性能
(很多题号达不到100%是因为leetcode加了新的测试案例进去)
1. 100%: 1, 19, 20, 21, 51, 52, 70, 92, 94, 102, 144, 145, 200, 300, 509, 700, 876, 912, 2248, O_40
2. 95%: 26, 104, 167, 206, 207, 210, 547, 704, 875, 
3. 85%: 112, 344
4. 60%: 
5. 其他: 


## Env
1. ubuntu 22.04.2 LTS
2. g++ (需要支持c++17标准)
3. python>=3.8