#include <leetcode>
using namespace leetcode;

/// 迭代法
class Solution {
   public:
    inline TreeNode* searchBST(TreeNode* root, int val) { return search_bst_node(root, val); }
};

int main() {
    TreeNode* root = to_tree({4, 2, 7, 1, 3});
    cout << Solution().searchBST(root, 2) << '\n';
}