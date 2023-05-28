#ifndef _LEETCODE_ALG_ARRAY_H
#define _LEETCODE_ALG_ARRAY_H 1

#include <_types.h>

inline double euclidean_dist(int x, int y, int x2, int y2, bool square = false) {
    int d = x2 - x, d2 = y2 - y;
    double res = d * d + d2 * d2;
    if (square) {
        return res;
    }
    res = sqrt(res);
    return res;
}

inline int manhattan_dist(int x, int y, int x2, int y2) {
    int d = x2 - x, d2 = y2 - y;
    return abs(d) + abs(d2);
}

#endif