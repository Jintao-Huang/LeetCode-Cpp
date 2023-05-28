#ifndef _LEETCODE_IO_H
#define _LEETCODE_IO_H 1
#include <_types.h>

namespace leetcode {
template <typename Tp>
ostream &operator<<(ostream &out, const vector<Tp> &nums) {
    // 支持matrix等.
    out << '[';
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
        const Tp &x = nums[i];
        if (i > 0) {
            cout << ", ";
        }
        out << x;
    }
    out << ']';
    return out;
}

template <typename Tp>
ostream &operator<<(ostream &out, const optional<Tp> &nums) {
    if (nums.has_value()) {
        out << nums.value();
    } else {
        out << "null";
    }
    return out;
}
}  // namespace leetcode
#endif
