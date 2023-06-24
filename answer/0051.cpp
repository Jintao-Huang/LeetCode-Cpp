
#include <leetcode>
using namespace leetcode;

class Solution {
   public:
    inline vector<vector<string>> solveNQueens(int n) {
        vector<bool> visited_c(n), visited_md(2 * n - 1), visited_cd(2 * n - 1);
        vector<int> path;
        vector<vector<int>> res;
        n_queens(n, visited_c, visited_md, visited_cd, path, res);
        vector<vector<string>> res_str;
        n_queens_tostring(res, res_str);
        return res_str;
    }
};

/// use unordered_set(slower)
class Solution2 {
   public:
    inline vector<vector<string>> solveNQueens(int n) {
        unordered_set<int> visited_c, visited_md, visited_cd;
        vector<int> path;
        vector<vector<int>> res;
        n_queens_us(n, visited_c, visited_md, visited_cd, path, res);
        vector<vector<string>> res_str;
        n_queens_tostring(res, res_str);
        return res_str;
    }
};

int main() {
    cout << Solution().solveNQueens(4) << '\n';
    cout << Solution2().solveNQueens(4) << '\n';
}