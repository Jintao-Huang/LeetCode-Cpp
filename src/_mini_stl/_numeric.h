// Author: Jintao Huang
// Email: huangjintao@mail.ustc.edu.cn
// Date:

#ifndef _MINI_STL_NUMERIC_H
#define _MINI_STL_NUMERIC_H 1
#include <_types.h>
// 只是用++first, 避免first++的性能开销(临时变量).
namespace mini_stl {
template <typename InputIterator, typename Tp, typename BinaryOperation = mini_stl::plus<>>
Tp accumulate(InputIterator first, InputIterator last, Tp init,
              BinaryOperation binary_op = BinaryOperation()) {
    while (first != last) {
        // binary_op: function<Tp(Tp, typename iterator_traits<InputIterator>::value_type)>
        init = mini_stl::move(binary_op(init, *first));
        ++first;
    }
    return init;
}
}  // namespace mini_stl
#endif