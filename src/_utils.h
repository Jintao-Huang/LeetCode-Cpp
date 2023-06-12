#ifndef _UTILS_H
#define _UTILS_H 1
#include <_types.h>
namespace std {
template <typename Tp>
Tp* malloc_c(int size) {
    return static_cast<Tp*>(malloc(size * sizeof(Tp)));
}
template <typename Tp>
Tp* realloc_c(Tp* old_ptr, int size) {
    return static_cast<Tp*>(realloc(old_ptr, size * sizeof(Tp)));
}

template <typename Tp>
Tp* memset_c(Tp* ptr, int value, int size) {
    // Tp为char, value可以是任意值.
    // Tp为int等, value只能是-1{0xffff...}, 0{0x0000...};
    return static_cast<Tp*>(memset(ptr, value, size * sizeof(Tp)));
}

template <typename Tp>
Tp* memcpy_c(Tp* dst, Tp* src, int size) {
    return static_cast<Tp*>(memcpy(dst, src, size * sizeof(Tp)));
}

template <typename Tp>
Tp* memmove_c(Tp* dst, Tp* src, int size) {
    return static_cast<Tp*>(memmove(dst, src, size * sizeof(Tp)));
}
}  // namespace std

#endif