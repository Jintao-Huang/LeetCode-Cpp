
#ifndef _MINI_STL_FUNCTIONAL_H
#define _MINI_STL_FUNCTIONAL_H 1
#include <_mini_stl/_utility.h>
namespace mini_stl {
template <typename Tp = void>
struct plus {
    // 隐式inline
    constexpr Tp operator()(const Tp& x, const Tp& y) const { return x + y; }
};

template <>
struct plus<void> {
    template <typename Tp, typename Up>
    constexpr auto operator()(Tp&& t, Up&& u) const
        -> decltype(mini_stl::forward<Tp>(t) + mini_stl::forward<Up>(u)) {
        return mini_stl::forward<Tp>(t) + mini_stl::forward<Up>(u);
    }
};

//
template <typename Tp = void>
struct multiplies {
    constexpr Tp operator()(const Tp& x, const Tp& y) const { return x * y; }
};

template <>
struct multiplies<void> {
    template <typename Tp, typename Up>
    constexpr auto operator()(Tp&& t, Up&& u) const
        -> decltype(mini_stl::forward<Tp>(t) + mini_stl::forward<Up>(u)) {
        return mini_stl::forward<Tp>(t) * mini_stl::forward<Up>(u);
    }
};
//
template <typename Tp = void>
struct less {
    constexpr bool operator()(const Tp& x, const Tp& y) const { return x < y; }
};
template <>
struct less<void> {
    template <typename Tp, typename Up>
    constexpr auto operator()(Tp&& t, Up&& u) const
        -> decltype(mini_stl::forward<Tp>(t) < mini_stl::forward<Up>(u)) {
        return mini_stl::forward<Tp>(t) < mini_stl::forward<Up>(u);
    }
};
//
template <typename Tp = void>
struct equal_to {
    constexpr bool operator()(const Tp& x, const Tp& y) const { return x == y; }
};
template <>
struct equal_to<void> {
    template <typename Tp, typename Up>
    constexpr auto operator()(Tp&& t, Up&& u) const
        -> decltype(mini_stl::forward<Tp>(t) < mini_stl::forward<Up>(u)) {
        return mini_stl::forward<Tp>(t) == mini_stl::forward<Up>(u);
    }
};

//
template <typename Tp = void>
struct less_equal {
    constexpr bool operator()(const Tp& x, const Tp& y) const { return x <= y; }
};
template <>
struct less_equal<void> {
    template <typename Tp, typename Up>
    constexpr auto operator()(Tp&& t, Up&& u) const
        -> decltype(mini_stl::forward<Tp>(t) < mini_stl::forward<Up>(u)) {
        return mini_stl::forward<Tp>(t) <= mini_stl::forward<Up>(u);
    }
};
}  // namespace mini_stl
#endif
