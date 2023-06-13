#include <leetcode>
using namespace leetcode;
class Solution {
   public:
    inline vector<vector<int>> levelOrder(TreeNode *root) {
        vector<vector<int>> res;
        level_order_traversal(root, res);
        return res;
    }
};

int main() {
    TreeNode *root = to_tree({3, 9, 20, nullopt, nullopt, 15, 7});
    cout << root << '\n';
    cout << Solution().levelOrder(root) << '\n';
    return 0;
}
