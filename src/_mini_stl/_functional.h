
#ifndef _MINI_STL_FUNCTIONAL_H
#define _MINI_STL_FUNCTIONAL_H 1

namespace mini_stl {
template <typename Tp = void>
struct plus : public std::binary_function<Tp, Tp, Tp> {
    constexpr Tp operator()(const Tp& x, const Tp& y) const { return x + y; }
};

template <>
struct plus<void> {
    template <typename Tp, typename Up>
    constexpr auto operator()(Tp&& t, Up&& u) const
        noexcept(noexcept(std::forward<Tp>(t) + std::forward<Up>(u)))
            -> decltype(std::forward<Tp>(t) + std::forward<Up>(u)) {
        return std::forward<Tp>(t) + std::forward<Up>(u);
    }
};
}  // namespace mini_stl
#endif
