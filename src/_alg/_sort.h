#ifndef _ALG_SORT_H
#define _ALG_SORT_H 1
#include <_alg/_search.h>
#include <_types.h>

namespace leetcode {

random_device __rd;
default_random_engine __gen(__rd());
inline int gen_randint(int lo, int hi) { return uniform_int_distribution<>(lo, --hi)(__gen); }

template <typename BiIterator, typename Tp>
pair<BiIterator, BiIterator> three_way_partition(BiIterator first, BiIterator last, Tp val) {
    // partition实现见mini_stl
    BiIterator it = first;
    while (it != last) {
        if (*it > val) {
            while (*--last > val) {
                if (it == last) {
                    return {first, last};
                }
            }
            iter_swap(it, last);
        } else if (*it < val) {
            iter_swap(first, it);
            ++first;
            ++it;
        } else {
            ++it;
        }
    }
    return {first, last};
}

template <typename RandomIterator>
void quick_sort(RandomIterator first, RandomIterator last) {
    if (last - first <= 1) {
        return;
    }
    auto _last_m1 = last - 1;
    // 随机数优化
    iter_swap(first + gen_randint(0, last - first), _last_m1);
    // iter_swap(get_mid(first, _last_m1), _last_m1);  // 也可以取mid.
    // 三路partition优化
    auto [pivot, pivot2] = three_way_partition(first, last, *_last_m1);
    quick_sort(first, pivot);
    quick_sort(pivot2, last);
}

template <typename RandomIterator>
void quick_sort2(RandomIterator first, RandomIterator last) {
    // 负面案例: 没有随机数优化[1, 2, 3, 4...顺序/逆序] O(n^2)
    //   没有三路partition优化([2, 2, 2, 2, ...相同元素] O(n^2)).
    if (last - first <= 1) {
        return;
    }
    auto _last_m1 = last - 1;
    RandomIterator pivot = partition(
        first, _last_m1, bind<>(less<>(), placeholders::_1, *_last_m1));  // _last_m1一定不满足pred
    iter_swap(pivot, _last_m1);
    quick_sort2(first, pivot);
    quick_sort2(pivot + 1, last);
}

template <typename RandomIterator>
void merge_sort(RandomIterator first, RandomIterator last) {
    if (last - first <= 1) {
        return;
    }
    RandomIterator mid = get_mid(first, last);
    merge_sort(first, mid);
    merge_sort(mid, last);
    inplace_merge(first, mid, last);
}

template <typename ForwardIterator>
void bubble_sort(ForwardIterator first, ForwardIterator last) {
    while (first != --last) {
        ForwardIterator p = first;
        while (p != last) {
            ForwardIterator _p_prev = p;
            ++p;
            if (*p < *_p_prev) {
                iter_swap(_p_prev, p);
            }
        }
    }
}

template <typename ForwardIterator>
void select_sort(ForwardIterator first, ForwardIterator last) {
    while (first != last) {
        iter_swap(first, min_element(first, last));  // 不使用 first++避免未定义行为(有两个first)
        ++first;
    }
}

template <typename ForwardIterator>
void insert_sort(ForwardIterator first, ForwardIterator last) {
    ForwardIterator it = first;
    ++it;
    while (it != last) {
        ForwardIterator _it_prev = it;
        ++it;
        rotate(upper_bound(first, _it_prev, *_it_prev), _it_prev, it);  // rotate ->1.
    }
}

}  // namespace leetcode
#endif