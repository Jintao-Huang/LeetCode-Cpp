// Author: Jintao Huang
// Email: huangjintao@mail.ustc.edu.cn
// Date:

#ifndef _ALG_SEARCH_H
#define _ALG_SEARCH_H 1
#include <_ds/_union_find.h>
#include <_lc/_lc_ds.h>
#include <_types.h>

namespace leetcode {
void n_queens_tostring(const vector<vector<int>> &vv, vector<vector<string>> &res) {
    int n = vv.size();
    if (n == 0) {
        return;
    }
    int m = vv[0].size();
    for (int i = 0; i < n; ++i) {
        const vector<int> &v = vv[i];
        vector<string> vs;
        for (const int &x : v) {
            string s(m, '.');
            s[x] = 'Q';
            vs.push_back(move(s));
        }
        res.push_back(move(vs));
    }
}

void n_queens(int n, vector<bool> &visited_c, vector<bool> &visited_md, vector<bool> &visited_cd,
              vector<int> &path, vector<vector<int>> &res) {
    /// visited: 列, 主对角线, 副对角线
    int idx = path.size();  // 第idx行
    if (idx == n) {
        res.push_back(path);
        return;
    }
    for (int i = 0; i < n; ++i) {
        int md_i = i - idx + n - 1, cd_i = i + idx;  //
        if (visited_c[i] || visited_md[md_i] || visited_cd[cd_i]) {
            continue;
        }
        path.push_back(i);
        visited_c[i] = true;
        visited_md[md_i] = true;
        visited_cd[cd_i] = true;
        n_queens(n, visited_c, visited_md, visited_cd, path, res);
        //
        path.pop_back();
        visited_c[i] = false;
        visited_md[md_i] = false;
        visited_cd[cd_i] = false;
    }
}

void n_queens_us(int n, unordered_set<int> &visited_c, unordered_set<int> &visited_md,
                 unordered_set<int> &visited_cd, vector<int> &path, vector<vector<int>> &res) {
    /// visited: 列, 主对角线, 副对角线
    int idx = path.size();
    if (idx == n) {
        res.push_back(path);
        return;
    }
    for (int i = 0; i < n; ++i) {
        int md_i = i - idx, cd_i = i + idx;  //
        if (visited_c.count(i) || visited_md.count(md_i) || visited_cd.count(cd_i)) {
            continue;
        }
        path.push_back(i);
        visited_c.insert(i);
        visited_md.insert(md_i);
        visited_cd.insert(cd_i);
        n_queens_us(n, visited_c, visited_md, visited_cd, path, res);
        //
        path.pop_back();
        visited_c.erase(i);
        visited_md.erase(md_i);
        visited_cd.erase(cd_i);
    }
}

void n_queens2(int n, vector<bool> &visited_c, vector<bool> &visited_md, vector<bool> &visited_cd,
               int idx, int &res) {
    /// visited: 列, 主对角线, 副对角线
    if (idx == n) {
        ++res;
        return;
    }
    for (int i = 0; i < n; ++i) {
        int md_i = i - idx + n - 1, cd_i = i + idx;  //
        if (visited_c[i] || visited_md[md_i] || visited_cd[cd_i]) {
            continue;
        }
        visited_c[i] = true;
        visited_md[md_i] = true;
        visited_cd[cd_i] = true;
        n_queens2(n, visited_c, visited_md, visited_cd, idx + 1, res);
        //
        visited_c[i] = false;
        visited_md[md_i] = false;
        visited_cd[cd_i] = false;
    }
}
///
void dfs_grid(vector<vector<char>> &grid, int i, int j) {
    grid[i][j] = '0';
    //
    int n = grid.size(), m = grid[0].size();
    if (i + 1 < n && grid[i + 1][j] == '1') {
        dfs_grid(grid, i + 1, j);
    }
    if (i - 1 >= 0 && grid[i - 1][j] == '1') {
        dfs_grid(grid, i - 1, j);
    }

    if (j + 1 < m && grid[i][j + 1] == '1') {
        dfs_grid(grid, i, j + 1);
    }

    if (j - 1 >= 0 && grid[i][j - 1] == '1') {
        dfs_grid(grid, i, j - 1);
    }
}

void bfs_grid(vector<vector<char>> &grid, int i, int j) {
    deque<tuple<int, int>> dq = {{i, j}};
    int n = grid.size(), m = grid[0].size();

    while (!dq.empty()) {
        auto [i, j] = dq.front();
        dq.pop_front();
        //
        if (i + 1 < n && grid[i + 1][j] == '1') {
            grid[i + 1][j] = '0';
            dq.push_back({i + 1, j});
        }
        if (i - 1 >= 0 && grid[i - 1][j] == '1') {
            grid[i - 1][j] = '0';
            dq.push_back({i - 1, j});
        }

        if (j + 1 < m && grid[i][j + 1] == '1') {
            grid[i][j + 1] = '0';
            dq.push_back({i, j + 1});
        }

        if (j - 1 >= 0 && grid[i][j - 1] == '1') {
            grid[i][j - 1] = '0';
            dq.push_back({i, j - 1});
        }
    }
}

int nums_connected_component_grid_xfs(vector<vector<char>> &grid, bool is_bfs = false) {
    int n = grid.size(), m = grid[0].size();
    function<void(vector<vector<char>> &, int, int)> xfs_grid;
    if (is_bfs) {
        xfs_grid = bfs_grid;
    } else {
        xfs_grid = dfs_grid;
    }
    //
    int count = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == '1') {
                ++count;
                xfs_grid(grid, i, j);
            }
        }
    }
    return count;
}

int nums_connected_component_grid_uf(vector<vector<char>> &grid) {
    int n = grid.size(), m = grid[0].size();
    UnionFind uf(n * m);
    int count = 0;
    //
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == '1') {
                ++count;
                int idx = i * m + j;
                //
                if (i + 1 < n && grid[i + 1][j] == '1' && uf.union_set(idx + m, idx)) {
                    --count;
                }
                if (j + 1 < m && grid[i][j + 1] == '1' && uf.union_set(idx + 1, idx)) {
                    --count;
                }
            }
        }
    }
    return count;
}
///
void dfs_graph_m(vector<vector<int>> &graph, vector<bool> &visited, int gn) {
    visited[gn] = true;
    int n = graph.size();
    for (int gn2 = 0; gn2 < n; ++gn2) {
        if (graph[gn][gn2] && !visited[gn2]) {
            dfs_graph_m(graph, visited, gn2);
        }
    }
}

void bfs_graph_m(vector<vector<int>> &graph, vector<bool> &visited, int gn) {
    deque<int> dq = {gn};
    int n = graph.size();
    //
    while (!dq.empty()) {
        int gn = dq.front();
        dq.pop_front();
        for (int gn2 = 0; gn2 < n; ++gn2) {
            if (graph[gn][gn2] && !visited[gn2]) {
                visited[gn2] = true;
                dq.push_back(gn2);
            }
        }
    }
}

int nums_connected_component_graph_m_xfs(vector<vector<int>> &graph, bool is_bfs = false) {
    int n = graph.size();
    vector<bool> visited(n);
    function<void(vector<vector<int>> &, vector<bool> &, int)> xfs_graph_m;
    if (is_bfs) {
        xfs_graph_m = dfs_graph_m;
    } else {
        xfs_graph_m = bfs_graph_m;
    }
    //
    int count = 0;
    for (int gn = 0; gn < n; ++gn) {
        if (visited[gn]) {
            continue;
        }
        ++count;
        xfs_graph_m(graph, visited, gn);
    }
    return count;
}

int nums_connected_component_graph_m_uf(vector<vector<int>> &graph) {
    int n = graph.size();
    UnionFind uf(n);
    int count = n;
    for (int gn = 0; gn < n; ++gn) {
        for (int gn2 = 0; gn2 < gn; ++gn2) {
            if (graph[gn][gn2]) {
                count -= uf.union_set(gn, gn2);
            }
        }
    }
    return count;
}

}  // namespace leetcode
#endif