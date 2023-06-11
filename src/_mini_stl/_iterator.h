
#ifndef _MINI_STL_ITERATOR_H
#define _MINI_STL_ITERATOR_H 1
#include <_types.h>

namespace mini_stl {
template <typename Iterator>
inline constexpr typename std::iterator_traits<Iterator>::iterator_category _iterator_category(
    const Iterator&) {
    return typename std::iterator_traits<Iterator>::iterator_category();
}
}  // namespace mini_stl
#endif