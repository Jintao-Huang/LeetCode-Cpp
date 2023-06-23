// Author: Jintao Huang
// Email: huangjintao@mail.ustc.edu.cn
// Date:

#ifndef _MINI_STL_CXX2A_H
#define _MINI_STL_CXX2A_H 1
#include <_types.h>

namespace leetcode {

template <typename RandomIterator, typename Compare = less<>>
void sort_heap_cxx2a(RandomIterator first, RandomIterator last, Compare comp = Compare()) {
    while (last - first >= 2) {
        pop_heap(first, last, comp);
        --last;
    }
}
}  // namespace leetcode

#endif