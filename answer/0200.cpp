#include <leetcode>
using namespace leetcode;

/// dfs
class Solution {
   public:
    inline int numIslands(vector<vector<char>>& grid) {
        return nums_connected_component_grid_xfs(grid);
    }
};

/// bfs
class Solution2 {
   public:
    inline int numIslands(vector<vector<char>>& grid) {
        return nums_connected_component_grid_xfs(grid, true);
    }
};

/// UF
class Solution3 {
   public:
    inline int numIslands(vector<vector<char>>& grid) {
        return nums_connected_component_grid_uf(grid);
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