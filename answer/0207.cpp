
#include <leetcode>
using namespace leetcode;

class Solution {
   public:
    bool canFinish(int numCourses, const vector<vector<int>>& prerequisites) {
        // build graph
        vector<vector<int>> graph_l(numCourses, vector<int>());
        vector<int> cnt(numCourses);
        int n = prerequisites.size();
        for (int i = 0; i < n; ++i) {
            int gn_to = prerequisites[i][0], gn_from = prerequisites[i][1];
            graph_l[gn_from].push_back(gn_to);
        }
        //
        vector<int> res;
        topo_sort_bfs(graph_l, res);
        return !res.empty();
    }
};

class Solution2 {
   public:
    bool canFinish(int numCourses, const vector<vector<int>>& prerequisites) {
        // build graph
        vector<vector<int>> graph_l(numCourses, vector<int>());
        vector<int> cnt(numCourses);
        int n = prerequisites.size();
        for (int i = 0; i < n; ++i) {
            int gn_to = prerequisites[i][0], gn_from = prerequisites[i][1];
            graph_l[gn_from].push_back(gn_to);
        }
        //
        vector<int> res;
        topo_sort_dfs(graph_l, res);
        return !res.empty();
    }
};

int main() {
    cout << Solution().canFinish(2, {{1, 0}, {0, 1}}) << '\n';
    cout << Solution().canFinish(2, {{1, 0}}) << '\n';

    cout << Solution2().canFinish(2, {{1, 0}, {0, 1}}) << '\n';
    cout << Solution2().canFinish(2, {{1, 0}}) << '\n';
}