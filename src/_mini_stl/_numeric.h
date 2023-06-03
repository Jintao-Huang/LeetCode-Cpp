
#ifndef _MINI_STL_NUMERIC_H
#define _MINI_STL_NUMERIC_H 1

namespace mini_stl {
template <typename InputIterator, typename Tp, typename BinaryOperation>
inline Tp accumulate(InputIterator first, InputIterator last, Tp init, BinaryOperation binary_op) {
    while (first != last) {
        // binary_op: function<Tp(Tp, typename iterator_traits<InputIterator>::value_type)>
        init = binary_op(init, *first++);
    }
    return init;
}
template <typename InputIterator, typename Tp>
inline Tp accumulate(InputIterator first, InputIterator last, Tp init) {
    return mini_stl::accumulate(first, last, init, std::plus<>());
}
}  // namespace mini_stl
#endif