

#ifndef _STL_ALGORITHM_H
#define _STL_ALGORITHM_H 1
/// 这里不进行move优化. (作者太菜了, 看stl看的脑壳痛)
namespace stl {
template <typename InputIterator, typename OutputIterator>
OutputIterator partial_sum(InputIterator first, InputIterator last, OutputIterator res) {
    typedef typename iterator_traits<InputIterator>::value_type value_type;
    if (first == last) {
        return res;
    }
    value_type val = *first;
    *res = val;
    while (++first != last) {
        val = val + *first;
        *++res = val;
    }
    return ++res;
}

template <typename InputIterator, typename OutputIterator>
OutputIterator copy(InputIterator first, InputIterator last, OutputIterator res) {
    while (first != last) {
        *res++ = *first++;
    }
    return res;
}

template <typename InputIterator, typename Tp>
Tp accumulate(InputIterator first, InputIterator last, Tp init) {
    // 注意: 这里的输出是Tp!!! 所以不要出现accumulate(:vector<double>, :vector<double>, :int)的情况.
    while (first != last) {
        init = init + *first++;
    }
    return init;
}
template <typename InputIterator, typename Tp, typename BinaryOperation>
Tp accumulate(InputIterator first, InputIterator last, Tp init, BinaryOperation binary_op) {
    while (first != last) {
        init = binary_op(init, *first++);
    }
    return init;
}
}  // namespace stl
#endif