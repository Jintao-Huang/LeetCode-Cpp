// Author: Jintao Huang
// Email: huangjintao@mail.ustc.edu.cn
// Date:

#ifndef _ALG_GRAPH_H
#define _ALG_GRAPH_H 1
#include <_types.h>

namespace leetcode {
void topo_sort_bfs(const vector<vector<int>>& graph_l, vector<int>& res) {
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

enum struct State {
    NOT_VISITED,
    VISITING,
    VISITED,
};

bool has_cycle(const vector<vector<int>>& graph_l, vector<State>& visited, vector<int>& res,
               int i) {
    visited[i] = State::VISITING;
    for (const int& j : graph_l[i]) {
        if (visited[j] == State::NOT_VISITED) {
            if (!has_cycle(graph_l, visited, res, j)) {
                return false;
            }
        } else if (visited[j] == State::VISITING) {
            res.clear();
            return false;
        }
    }
    visited[i] = State::VISITED;
    res.push_back(i);
    return true;
}

void topo_sort_dfs(const vector<vector<int>>& graph_l, vector<int>& res) {
    int n = graph_l.size();
    vector<State> visited(n);
    for (int i = 0; i < n; ++i) {
        if (visited[i] == State::NOT_VISITED) {
            if (!has_cycle(graph_l, visited, res, i)) {
                res.clear();
                break;
            }
        }
    }
}
}  // namespace leetcode

#endif