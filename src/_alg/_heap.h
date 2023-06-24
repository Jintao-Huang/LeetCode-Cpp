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

template <typename RandomIterator, typename DT, typename Tp, typename Compare = less<>>
void push_heap_lc(RandomIterator first, DT hole_index, DT top_index, Tp val,
                  const Compare& comp = Compare()) {
    /// 上滤
    DT parent = get_parent(hole_index);
    while (hole_index > top_index && comp(*(first + parent), val)) {
        *(first + hole_index) = move(*(first + parent));
        hole_index = parent;
        parent = get_parent(hole_index);
    }
    *(first + hole_index) = move(val);
}

template <typename RandomIterator, typename DT, typename Tp, typename Compare = less<>>
void adjust_heap_lc(RandomIterator first, DT hole_index, DT len, Tp val,
                    const Compare& comp = Compare()) {
    /// 下滤
    const DT top_index = hole_index;
    DT second_child = hole_index;
    DT len_parent = get_parent(len);     // 最后一个节点的下一个的父节点.
    while (second_child < len_parent) {  // 一定有两个child
        second_child = get_rchild(second_child);
        if (comp(*(first + second_child), *(first + (second_child - 1)))) {
            --second_child;
        }
        *(first + hole_index) = move(*(first + second_child));
        hole_index = second_child;
    }
    // len偶数: 边的数量为奇数, 即最后一个父节点只有1个子节点.
    if ((len & 1) == 0 && get_parent(len - 1) == second_child) {
        second_child = get_rchild(second_child);
        --second_child;
        *(first + hole_index) = move(*(first + second_child));
        hole_index = second_child;
    }
    push_heap_lc(first, hole_index, top_index, move(val), comp);
}

template <typename RandomIterator, typename Compare = less<>>
inline void pop_heap_lc(RandomIterator first, RandomIterator last, RandomIterator res,
                        const Compare& comp = Compare()) {
    typedef typename iterator_traits<RandomIterator>::value_type VT;
    typedef typename iterator_traits<RandomIterator>::difference_type DT;

    VT val = move(*res);
    *res = move(*first);
    adjust_heap_lc(first, static_cast<DT>(0), static_cast<DT>(last - first), move(val), comp);
}


template <typename RandomIterator, typename Compare = less<>>
void heap_select_lc(RandomIterator first, RandomIterator mid, RandomIterator last,
                    const Compare& comp = Compare()) {
    std::make_heap(first, mid, comp);
    for (RandomIterator it = mid; it != last; ++it) {
        if (comp(*it, *first)) {
            pop_heap_lc(first, mid, it, comp);
        }
    }
}

}  // namespace leetcode

#endif
