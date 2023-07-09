
// Author: Jintao Huang
// Email: huangjintao@mail.ustc.edu.cn
// Date:

#ifndef _DS_UNION_FIND_H
#define _DS_UNION_FIND_H 1

#include <_types.h>

namespace leetcode {
class UnionFind {
   public:
    UnionFind(int n) {
        parent.resize(n, -1);
        count.resize(n, 1);
    }
    int get_root(int i) {
        if (parent[i] == -1) {
            return i;
        }
        parent[i] = get_root(parent[i]);
        return parent[i];
    }

    bool union_set(int i, int j) {
        int root_i = get_root(i);
        int root_j = get_root(j);
        //
        if (root_i == root_j) {
            return false;
        }
        //
        if (count[root_i] > count[root_j]) {
            swap(root_i, root_j);
        }
        parent[root_j] = root_i;
        count[root_j] += count[root_i];
        return true;
    }

    inline int get_count(int idx) { return count[idx]; }

   private:
    vector<int> parent;
    vector<int> count;  // 每个set有多少个elem. 只有root有效.
};
}  // namespace leetcode
#endif