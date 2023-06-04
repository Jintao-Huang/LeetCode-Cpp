#ifndef _MINI_STL_UTILITY_H
#define _MINI_STL_UTILITY_H 1
#include <_types.h>
namespace mini_stl {
template <typename _Tp>
constexpr typename std::remove_reference<_Tp>::type&& move(_Tp&& __t) noexcept {
    return static_cast<typename std::remove_reference<_Tp>::type&&>(__t);
}
template <typename _Tp>
constexpr _Tp&& forward(typename std::remove_reference<_Tp>::type& __t) noexcept {
    return static_cast<_Tp&&>(__t);
}

template <typename _Tp>
constexpr _Tp&& forward(typename std::remove_reference<_Tp>::type&& __t) noexcept {
    static_assert(!std::is_lvalue_reference<_Tp>::value,
                  "std::forward must not be used to convert an rvalue to an lvalue");
    return static_cast<_Tp&&>(__t);
}

}  // namespace mini_stl
#endif