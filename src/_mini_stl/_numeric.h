
#ifndef _MINI_STL_NUMERIC_H
#define _MINI_STL_NUMERIC_H 1
#include <_types.h>

namespace mini_stl {
template <typename InputIterator, typename Tp, typename BinaryOperation>
Tp accumulate(InputIterator first, InputIterator last, Tp init, BinaryOperation binary_op) {
    // 注意: 这里的输出是Tp!!! 所以不要出现accumulate(:vector<double>, :vector<double>, :int)的情况.
    // 可以出现accumulate(:vector<int>, :vector<int>, :double)的情况.
    while (first != last) {
        // binary_op: function<Tp(Tp, typename iterator_traits<InputIterator>::value_type)>
        init = binary_op(init, *first++);
    }
    return init;
}
template <typename InputIterator, typename Tp>
inline Tp accumulate(InputIterator first, InputIterator last, Tp init) {
    return mini_stl::accumulate(first, last, init, plus<>());
}

}  // namespace mini_stl
#endif