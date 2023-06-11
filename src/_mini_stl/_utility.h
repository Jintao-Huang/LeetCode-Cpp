#ifndef _MINI_STL_UTILITY_H
#define _MINI_STL_UTILITY_H 1
#include <_types.h>
namespace mini_stl {
template <typename Tp>
inline constexpr typename std::remove_reference<Tp>::type&& move(Tp&& t) noexcept {
    return static_cast<typename std::remove_reference<Tp>::type&&>(t);
}
template <typename Tp>
inline constexpr Tp&& forward(typename std::remove_reference<Tp>::type& t) noexcept {
    return static_cast<Tp&&>(t);
}

template <typename Tp>
inline constexpr Tp&& forward(typename std::remove_reference<Tp>::type&& t) noexcept {
    static_assert(!std::is_lvalue_reference<Tp>::value,
                  "std::forward must not be used to convert an rvalue to an lvalue");
    return static_cast<Tp&&>(t);
}
}  // namespace mini_stl
#endif