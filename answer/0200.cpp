#include <leetcode>
using namespace leetcode;

/// dfs
class Solution {
   public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        //
        int count = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == '1') {
                    ++count;
                    dfs(grid, i, j);
                }
            }
        }
        return count;
    }
};

/// bfs
class Solution2 {
   public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        //
        int count = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == '1') {
                    ++count;
                    bfs(grid, i, j);
                }
            }
        }
        return count;
    }
};

/// UF

class Solution3 {
   public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        //
        UnionFind uf(n * m);
        int count = 0;
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
};

int main() {
    {
        vector<vector<char>> grid = {{'1', '1', '0', '0', '0'},
                                     {'1', '1', '0', '0', '0'},
                                     {'0', '0', '1', '0', '0'},
                                     {'0', '0', '0', '1', '1'}};
        cout << Solution().numIslands(grid) << '\n';
    }
    {
        vector<vector<char>> grid = {{'1', '1', '0', '0', '0'},
                                     {'1', '1', '0', '0', '0'},
                                     {'0', '0', '1', '0', '0'},
                                     {'0', '0', '0', '1', '1'}};
        cout << Solution2().numIslands(grid) << '\n';
    }
    {
        vector<vector<char>> grid = {{'1', '1', '0', '0', '0'},
                                     {'1', '1', '0', '0', '0'},
                                     {'0', '0', '1', '0', '0'},
                                     {'0', '0', '0', '1', '1'}};
        cout << Solution3().numIslands(grid) << '\n';
    }
}