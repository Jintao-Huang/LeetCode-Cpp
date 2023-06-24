// Author: Jintao Huang
// Email: huangjintao@mail.ustc.edu.cn
// Date:

#ifndef _ALG_SORT_H
#define _ALG_SORT_H 1
#include <_alg/_bisect.h>
#include <_cxx2a.h>
#include <_types.h>

namespace leetcode {

random_device __rd;
default_random_engine __gen(__rd());
inline int gen_randint(int a, int b) {
    /// [a..b]
    return uniform_int_distribution<>(a, b)(__gen);
}

template <typename BiIterator, typename Tp, typename Compare = less<>>
pair<BiIterator, BiIterator> three_way_partition(BiIterator first, BiIterator last, Tp val,
                                                 const Compare &comp = Compare()) {
    /// partition实现见mini_stl.
    // note: 这里的Tp val不可以写成const Tp& val, 避免引用的内容是数组中的内容, 导致错误.
    BiIterator it = first;
    while (it != last) {
        if (comp(val, *it)) {
            while (comp(val, *--last)) {
                if (it == last) {
                    return {first, last};
                }
            }
            iter_swap(it, last);
        } else if (comp(*it, val)) {
            iter_swap(first, it);
            ++first;
            ++it;
        } else {
            ++it;
        }
    }
    // [first..last)都==val
    return {first, last};
}

template <typename RandomIterator, typename Compare = less<>>
void quick_sort(RandomIterator first, RandomIterator last, const Compare &comp = Compare()) {
    if (last - first <= 1) {
        return;
    }
    auto _last_m1 = last - 1;
    // 随机数优化
    iter_swap(first + gen_randint(0, _last_m1 - first), _last_m1);
    // iter_swap(get_mid(first, _last_m1), _last_m1);  // 也可以取mid.
    // 三路partition优化
    auto [pivot, pivot2] = three_way_partition(first, last, *_last_m1, comp);
    quick_sort(first, pivot, comp);
    quick_sort(pivot2, last, comp);
}

template <typename BiIterator, typename Compare = less<>>
inline BiIterator partition_lc(BiIterator first, BiIterator last, const Compare &comp = Compare()) {
    --last;
    BiIterator pivot = partition(first, last, bind<>(comp, placeholders::_1, *last));
    iter_swap(pivot, last);
    return pivot;
}

template <typename RandomIterator, typename Compare = less<>>
void quick_sort2(RandomIterator first, RandomIterator last, const Compare &comp = Compare()) {
    /// 反面案例: 没有随机数优化[1, 2, 3, 4...顺序/逆序] O(n^2)
    ///   没有三路partition优化([2, 2, 2, 2, ...相同元素] O(n^2).
    if (last - first <= 1) {
        return;
    }
    RandomIterator pivot = partition_lc(first, last, comp);  // _last_m1一定不满足pred
    quick_sort2(first, pivot, comp);
    quick_sort2(pivot + 1, last, comp);
}

template <typename RandomIterator, typename Compare = less<>>
void merge_sort(RandomIterator first, RandomIterator last, const Compare &comp = Compare()) {
    if (last - first <= 1) {
        return;
    }
    RandomIterator mid = get_mid(first, last);
    merge_sort(first, mid, comp);
    merge_sort(mid, last, comp);
    inplace_merge(first, mid, last, comp);
}

template <typename RandomIterator, typename Compare = less<>>
void heap_sort(RandomIterator first, RandomIterator last, const Compare &comp = Compare()) {
    make_heap(first, last, comp);
    sort_heap_cxx2a(first, last, comp);
}

template <typename ForwardIterator, typename Compare = less<>>
void bubble_sort(ForwardIterator first, ForwardIterator last, const Compare &comp = Compare()) {
    while (first != --last) {
        ForwardIterator p = first;
        while (p != last) {
            ForwardIterator _p_prev = p;
            ++p;
            if (comp(*p, *_p_prev)) {
                iter_swap(_p_prev, p);
            }
        }
    }
}

template <typename ForwardIterator, typename Compare = less<>>
void select_sort(ForwardIterator first, ForwardIterator last, const Compare &comp = Compare()) {
    while (first != last) {
        iter_swap(first,
                  min_element(first, last, comp));  // 不使用 first++避免未定义行为(有两个first)
        ++first;
    }
}

template <typename ForwardIterator, typename Compare = less<>>
void insert_sort(ForwardIterator first, ForwardIterator last, const Compare &comp = Compare()) {
    ForwardIterator it = first;
    ++it;
    while (it != last) {
        ForwardIterator _it_prev = it;
        ++it;
        rotate(upper_bound(first, _it_prev, *_it_prev, comp), _it_prev, it);  // rotate ->1.
    }
}

/// count_sort: Ot(n+k), Os(n+k). k = max_val + 1 - min_val. (只支持整型). 稳定.
/// bucket_sort: Ot(n+k), Os(n+k). k为桶个数. (支持整型, 浮点数等. 桶排序是计数排序的泛化,
/// 每个桶需要单独排序). 稳定. radix_sort: Ot(nk). k为位数. (对每一位依次稳定排序, 先低位, 再高位)
template <typename ForwardIterator>
void count_sort(ForwardIterator first, ForwardIterator last, const int &min_val,
                const int &max_val) {
    /// [min_val..max_val]. hash的思想
    int len = max_val + 1 - min_val;
    vector<int> v(len);
    ForwardIterator p = first;
    while (p != last) {
        ++v[*p - min_val];
        ++p;
    }
    //
    for (int i = 0; i < len; ++i) {
        int val = i + min_val;
        int count = v[i];
        fill(first, first + count, val);
        first += count;
    }
}

}  // namespace leetcode
#endif