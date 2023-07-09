#include <leetcode>
using namespace leetcode;

/// dfs
class Solution {
   public:
    inline int findCircleNum(vector<vector<int>>& isConnected) {
        return nums_connected_component_graph_m_xfs(isConnected);
    }
};

/// bfs
class Solution2 {
   public:
    inline int findCircleNum(vector<vector<int>>& isConnected) {
        return nums_connected_component_graph_m_xfs(isConnected, true);
    }
};

/// UF
class Solution3 {
   public:
    inline int findCircleNum(vector<vector<int>>& isConnected) {
        return nums_connected_component_graph_m_uf(isConnected);
    }
};

int main() {
    {
        vector<vector<int>> isConnected = {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};
        cout << Solution().findCircleNum(isConnected) << '\n';
    }
    {
        vector<vector<int>> isConnected = {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};
        cout << Solution2().findCircleNum(isConnected) << '\n';
    }
    {
        vector<vector<int>> isConnected = {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};
        cout << Solution3().findCircleNum(isConnected) << '\n';
    }
}