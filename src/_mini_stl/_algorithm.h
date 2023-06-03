
#ifndef _MINI_STL_ALGORITHM_H
#define _MINI_STL_ALGORITHM_H 1

namespace mini_stl {
template <typename InputIterator, typename OutputIterator, typename BinaryOperation>
OutputIterator partial_sum(InputIterator first, InputIterator last, OutputIterator res,
                           BinaryOperation binary_op) {
    if (first == last) {
        return res;
    }
    typename std::iterator_traits<InputIterator>::value_type val = *first;
    *res = val;
    while (++first != last) {
        val = binary_op(val, *first);
        *++res = val;
    }
    return ++res;
}

template <typename InputIterator, typename OutputIterator>
inline OutputIterator partial_sum(InputIterator first, InputIterator last, OutputIterator res) {
    return mini_stl::partial_sum(first, last, res, std::plus<>());
}

//
template <typename InputIterator, typename OutputIterator>
OutputIterator copy(InputIterator first, InputIterator last, OutputIterator res) {
    while (first != last) {
        *res++ = *first++;
    }
    return res;
}

template <typename InputIterator, typename Predicate>
typename std::iterator_traits<InputIterator>::difference_type count_if(InputIterator first,
                                                                       InputIterator last,
                                                                       Predicate pred) {
    typename std::iterator_traits<InputIterator>::difference_type res = 0;
    while (first != last) {
        if (pred(*first++)) {
            ++res;
        }
    }
    return res;
}

template <typename InputIterator, typename Tp>
inline typename std::iterator_traits<InputIterator>::difference_type count(InputIterator first,
                                                                           InputIterator last,
                                                                           const Tp& val) {
    return mini_stl::count_if(first, last, std::bind(std::equal_to<>(), std::placeholders::_1, val));
}

}  // namespace mini_stl
#endif