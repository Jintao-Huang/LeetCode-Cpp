// Author: Jintao Huang
// Email: huangjintao@mail.ustc.edu.cn
// Date:

#ifndef _ALG_SEARCH_H
#define _ALG_SEARCH_H 1
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
        n_queens2(n, visited_c, visited_md, visited_cd, idx+1, res);
        //
        visited_c[i] = false;
        visited_md[md_i] = false;
        visited_cd[cd_i] = false;
    }
}


}  // namespace leetcode
#endif