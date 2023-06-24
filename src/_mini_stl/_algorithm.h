// Author: Jintao Huang
// Email: huangjintao@mail.ustc.edu.cn
// Date:

#ifndef _MINI_STL_ALGORITHM_H
#define _MINI_STL_ALGORITHM_H 1
#include <_alg/_heap.h>
#include <_cxx2a.h>
#include <_mini_stl/_functional.h>
#include <_mini_stl/_iterator.h>
namespace mini_stl {
template <typename InputIterator, typename OutputIterator,
          typename BinaryOperation = mini_stl::plus<>>
OutputIterator partial_sum(InputIterator first, InputIterator last, OutputIterator res,
                           BinaryOperation binary_op = BinaryOperation()) {
    if (first == last) {
        return res;
    }
    typename std::iterator_traits<InputIterator>::value_type val = *first;
    *res = val;
    while (++first != last) {
        val = binary_op(mini_stl::move(val), *first);
        *++res = val;
    }
    return ++res;
}

//
template <typename InputIterator, typename OutputIterator>
OutputIterator copy(InputIterator first, InputIterator last, OutputIterator res) {
    /// TODO: 使用memmove加速
    while (first != last) {
        *res = *first;
        ++first;
        ++res;
    }
    return res;
}

template <typename InputIterator, typename UnaryPredicate>
typename std::iterator_traits<InputIterator>::difference_type count_if(InputIterator first,
                                                                       InputIterator last,
                                                                       UnaryPredicate unary_pred) {
    typename std::iterator_traits<InputIterator>::difference_type res = 0;
    while (first != last) {
        if (unary_pred(*first)) {
            ++res;
        }
        ++first;
    }
    return res;
}

template <typename InputIterator, typename Tp>
inline typename std::iterator_traits<InputIterator>::difference_type count(InputIterator first,
                                                                           InputIterator last,
                                                                           const Tp& val) {
    return mini_stl::count_if(first, last,
                              std::bind(mini_stl::equal_to<>(), std::placeholders::_1, val));
}
//
template <typename InputIterator1, typename InputIterator2, typename OutputIterator,
          typename Compare = mini_stl::less<>>
OutputIterator merge(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2,
                     InputIterator2 last2, OutputIterator res, Compare comp = Compare()) {
    while (first1 != last1 && first2 != last2) {
        if (comp(*first2, *first1)) {  // *first1 > *first2
            *res = *first2;
            ++first2;
        } else {  // *first1 <= *first2
            *res = *first1;
            ++first1;
        }
        ++res;
    }
    return mini_stl::copy(first2, last2, mini_stl::copy(first1, last1, res));
}

template <typename ForwardIterator, typename Predicate>
ForwardIterator _partition(ForwardIterator first, ForwardIterator last, Predicate pred,
                           std::forward_iterator_tag) {
    /// first之前的元素满足pred. first及其之后的元素不满足pred.
    // 避免自己和自己swap的消耗
    if (first == last) {
        return first;
    }
    while (pred(*first)) {
        if (++first == last) {
            return first;  // 即last
        }
    }
    //
    ForwardIterator it = first;
    while (++it != last) {
        if (pred(*it)) {
            std::iter_swap(first, it);
            ++first;
        }
    }
    return first;
}

template <typename BiIterator, typename Predicate>
BiIterator _partition(BiIterator first, BiIterator last, Predicate pred,
                      std::bidirectional_iterator_tag) {
    /// first之前的元素满足pred. first及其之后的元素不满足pred.
    while (true) {
        while (true) {
            if (first == last) {
                return first;
            } else if (pred(*first)) {  // pred(nums[lo])
                ++first;
            } else {
                break;
            }
        }
        --last;
        while (true) {
            if (first == last) {
                return first;
            } else if (pred(*last)) {  // pred(nums[hi])
                break;
            } else {
                --last;
            }
        }
        std::iter_swap(first, last);
        ++first;
    }
}

template <typename ForwardIterator, typename Predicate>
ForwardIterator partition(ForwardIterator first, ForwardIterator last, Predicate pred) {
    return mini_stl::_partition(first, last, pred, mini_stl::_iterator_category(first));
}

template <typename ForwardIterator, typename BinaryPredicate = equal_to<>>
ForwardIterator adjacent_find(ForwardIterator first, ForwardIterator last,
                              BinaryPredicate binary_pred = BinaryPredicate()) {
    if (first == last) {
        return last;
    }
    ForwardIterator next = first;
    while (++next != last) {
        if (binary_pred(*first, *next)) {
            return first;
        }
        first = next;
    }
    return last;
}

template <typename ForwardIterator, typename BinaryPredicate = equal_to<>>
ForwardIterator unique(ForwardIterator first, ForwardIterator last,
                       BinaryPredicate binary_pred = BinaryPredicate()) {
    first = mini_stl::adjacent_find(first, last, binary_pred);
    if (first == last) {
        return last;
    }

    ForwardIterator dest = first;
    ++first;
    while (++first != last)
        if (!binary_pred(*dest, *first)) {
            *++dest = mini_stl::move(*first);
        }
    return ++dest;
}

template <typename ForwardIterator1, typename ForwardIterator2>
inline void iter_swap(ForwardIterator1 a, ForwardIterator2 b) {
    std::swap(*a, *b);
}
template <typename BiIterator>
void _reverse(BiIterator first, BiIterator last, std::bidirectional_iterator_tag) {
    while (true)
        if (first == last || first == --last) {
            return;
        }

        else {
            mini_stl::iter_swap(first, last);
            ++first;
        }
}

template <typename RandomIterator>
void _reverse(RandomIterator first, RandomIterator last, std::random_access_iterator_tag) {
    if (first == last) {
        return;
    }
    --last;
    while (first < last) {
        mini_stl::iter_swap(first, last);
        ++first;
        --last;
    }
}

template <typename RandomIterator>
void reverse(RandomIterator first, RandomIterator last) {
    return mini_stl::_reverse(first, last, mini_stl::_iterator_category(first));
}

template <typename ForwardIterator, typename Compare = mini_stl::less<>>
ForwardIterator min_element(ForwardIterator first, ForwardIterator last, Compare comp = Compare()) {
    if (first == last) {
        return first;
    }
    ForwardIterator res = first;
    while (++first != last) {
        if (comp(*first, *res)) {
            res = first;
        }
    }

    return res;
}
using leetcode::get_parent, leetcode::get_rchild;
using leetcode::push_heap_lc, leetcode::pop_heap_lc, leetcode::adjust_heap_lc;
/// heap
template <typename RandomIterator, typename Compare = mini_stl::less<>>
void make_heap(RandomIterator first, RandomIterator last, Compare comp = Compare()) {
    // 默认: 大根堆
    typedef typename std::iterator_traits<RandomIterator>::value_type VT;
    typedef typename std::iterator_traits<RandomIterator>::difference_type DT;
    const DT len = last - first;
    if (len <= 1) {
        return;
    }
    DT parent = get_parent(len - 1);
    while (parent >= 0) {
        VT val = mini_stl::move(*(first + parent));
        adjust_heap_lc(first, parent, len, mini_stl::move(val), comp);
        --parent;
    }
}

template <typename RandomIterator, typename Compare = mini_stl::less<>>
inline void push_heap(RandomIterator first, RandomIterator last, Compare comp = Compare()) {
    typedef typename std::iterator_traits<RandomIterator>::difference_type DT;
    DT len = last - first;
    push_heap_lc(first, --len, static_cast<DT>(0), mini_stl::move(*(last - 1)), comp);
}

template <typename RandomIterator, typename Compare = mini_stl::less<>>
inline void pop_heap(RandomIterator first, RandomIterator last, Compare comp = Compare()) {
    typedef typename std::iterator_traits<RandomIterator>::difference_type DT;
    DT len = last - first;
    if (len <= 1) {
        return;
    }
    --last;
    pop_heap_lc(first, last, last, comp);
}
using leetcode::heap_select_lc, leetcode::sort_heap_cxx2a;
template <typename RandomIterator, typename Compare = mini_stl::less<>>
inline void partial_sort(RandomIterator first, RandomIterator mid, RandomIterator last,
                  const Compare& comp = Compare()) {
    heap_select_lc(first, mid, last, comp);
    sort_heap_cxx2a(first, mid, comp);
}
}  // namespace mini_stl
#endif