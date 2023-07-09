// Author: Jintao Huang
// Email: huangjintao@mail.ustc.edu.cn
// Date:

#ifndef _ALG_GRAPH_H
#define _ALG_GRAPH_H 1
#include <_types.h>

namespace leetcode {
void topo_sort(const vector<vector<int>>& graph_l, vector<int>& res) {
    int n = graph_l.size();
    vector<int> in_degree(n);
    for (const vector<int>& g : graph_l) {
        for (const int& gn_to : g) {
            ++in_degree[gn_to];
        }
    }
    //
    for (int gn = 0; gn < n; ++gn) {
        if (!in_degree[gn]) {
            res.push_back(gn);
        }
    }
    //
    int i = -1;
    while (++i < res.size()) {
        int gn_from = res[i];
        for (const int& gn_to : graph_l[gn_from]) {
            if (!--in_degree[gn_to]) {
                res.push_back(gn_to);
            }
        }
    }
    if (res.size() < n) {
        res.clear();
    }
}
}  // namespace leetcode

#endif