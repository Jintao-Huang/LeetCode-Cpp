#include <leetcode>
using namespace leetcode;

/// 递归法
class Solution {
   public:
    inline vector<int> inorderTraversal(TreeNode *root) {
        vector<int> res;
        inorder_traversal(root, res);
        return res;
    }
};

/// 迭代法
class Solution2 {
   public:
    inline vector<int> inorderTraversal(TreeNode *root) {
        vector<int> res;
        inorder_traversal3(root, res);
        return res;
    }
};

int main() {
    TreeNode *root = to_tree({1, nullopt, 2, 3});
    cout << root << '\n';
    cout << Solution().inorderTraversal(root) << '\n';
    cout << Solution2().inorderTraversal(root) << '\n';
    return 0;
}