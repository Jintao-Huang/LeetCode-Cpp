// Author: Jintao Huang
// Email: huangjintao@mail.ustc.edu.cn
// Date:

#ifndef _ALG_ARRAY_H
#define _ALG_ARRAY_H 1

#include <_alg/_sort.h>
#include <_types.h>

namespace leetcode {
template <typename Tp>
inline double euclidean_dist(Tp x, Tp y, Tp x2, Tp y2, bool square = false) {
    Tp d = x2 - x, d2 = y2 - y;
    double res = d * d + d2 * d2;
    if (square) {
        return res;
    }
    res = sqrt(res);
    return res;
}

template <typename Tp>
inline int manhattan_dist(Tp x, Tp y, Tp x2, Tp y2) {
    Tp d = x2 - x, d2 = y2 - y;
    return abs(d) + abs(d2);
}

template <typename Tp, typename BinaryOperation = plus<Tp>>
void partial_sum_lc(const vector<Tp>& nums, vector<Tp>& res,
                    BinaryOperation binary_op = BinaryOperation()) {
    typename vector<Tp>::const_iterator first = nums.begin(), last = nums.end();
    if (first == last) {
        return;
    }
    if (res.empty()) {
        res.push_back(*first);
        ++first;
    }
    while (first != last) {
        res.push_back(binary_op(res.back(), *first));
        ++first;
    }
}

bool bracket_matching(const string& s) {
    vector<char> st;
    int n = s.size();
    for (int i = 0; i < n; ++i) {
        char c = s[i];
        //
        if (c == ')' || c == ']' || c == '}') {
            if (st.empty()) {
                return false;
            }
            //
            if (c == ')' && st.back() != '(' || c == ']' && st.back() != '[' ||
                c == '}' && st.back() != '{') {
                return false;
            }
            st.pop_back();
            continue;
        }
        //
        st.push_back(c);
    }
    return st.empty();
}

void two_sum(const vector<int>& nums, int target, vector<int>& res) {
    /// res. start from 0.
    unordered_map<int, int> mapper;
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
        int x = nums[i], tmx = target - x;  // minus
        if (mapper.count(tmx)) {
            res.resize(2);
            res[0] = mapper[tmx];
            res[1] = i;
            return;
        }
        //
        mapper[x] = i;
    }
}

template <typename Tp>
int get_vv_size(const vector<vector<Tp>>& vv) {
    int n = vv.size();
    int size = 0;
    for (int i = 0; i < n; ++i) {
        size += vv[i].size();
    }
    return size;
}

template <typename Tp>
void flatten_vv(const vector<vector<Tp>>& vv, vector<Tp>& res) {
    int n = vv.size();
    for (int i = 0; i < n; ++i) {
        const vector<Tp>& v = vv[i];
        int m = v.size();
        for (int j = 0; j < m; ++j) {
            res.push_back(v[j]);
        }
    }
}

int fib(int n) {
    // fib(0)=0, 1, 1, 2...
    if (n == 0) {
        return 0;
    }
    int i = 0, j = 1;
    while (--n) {
        int tmp = i;
        i = j;
        j += tmp;
    }
    return j;
}

template <typename Tp>
void intersection(const vector<vector<Tp>>& nums, vector<Tp>& res) {
    unordered_map<Tp, int> um;
    int n = nums.size();
    if (!n) {
        return;
    };
    //
    for (int i = 0; i < n - 1; ++i) {
        int m = nums[i].size();
        for (int j = 0; j < m; ++j) {
            const Tp& x = nums[i][j];
            ++um[x];
        }
    }
    //
    int i = n - 1;
    int m = nums[i].size();
    for (int j = 0; j < m; ++j) {
        const Tp& x = nums[i][j];
        if (um[x] == n - 1) {
            res.push_back(x);
        }
    }
}

template <typename RandomIterator>
typename iterator_traits<RandomIterator>::value_type random_select(RandomIterator first,
                                                                   RandomIterator last, int k) {
    /// k: 从0开始
    // [first..last)
    auto k_it = first + k;
    while (true) {
        RandomIterator _last_m1 = last - 1;
        iter_swap(first + gen_randint(0, _last_m1 - first), _last_m1);
        auto [pivot, pivot2] = three_way_partition(first, last, *_last_m1);
        if (k_it < pivot) {
            last = pivot;
        } else if (k_it >= pivot2) {
            first = pivot2;
        } else {
            return *pivot;
        }
    }
}

template <typename RandomIterator>
typename iterator_traits<RandomIterator>::value_type random_select2(RandomIterator first,
                                                                    RandomIterator last, int k) {
    /// k: 从0开始
    // [first..last)
    auto k_it = first + k;
    while (true) {
        RandomIterator _last_m1 = last - 1;
        iter_swap(first + gen_randint(0, _last_m1 - first), _last_m1);
        RandomIterator pivot = partition_lc(first, last);
        if (k_it < pivot) {
            last = pivot;
        } else if (k_it > pivot) {
            first = pivot + 1;
        } else {
            return *pivot;
        }
    }
}

}  // namespace leetcode

#endif