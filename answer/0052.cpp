
#include <leetcode>
using namespace leetcode;


class Solution {
public:
    int totalNQueens(int n) {
        int res = 0;
        vector<bool> visited_c(n), visited_md(2 * n - 1), visited_cd(2 * n - 1);
        n_queens2(n, visited_c, visited_md, visited_cd, 0, res);
        return res;
    }
};

int main() { cout << Solution().totalNQueens(4) << '\n'; }