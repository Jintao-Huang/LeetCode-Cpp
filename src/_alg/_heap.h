// Author: Jintao Huang
// Email: huangjintao@mail.ustc.edu.cn
// Date:

#ifndef _ALG_HEAP_H
#define _ALG_HEAP_H 1

#include <_types.h>

namespace leetcode {
template <typename Tp>  // int, unsigned int, ..
inline Tp get_parent(Tp child) {
    return (--child) >> 1;
}
template <typename Tp>
inline Tp get_rchild(Tp parent) {
    // lchild = rchild - 1
    return ++parent << 1;
}
}  // namespace leetcode

#endif
