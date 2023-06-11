#include <leetcode>
using namespace leetcode;

/// 递归法
class Solution {
   public:
    inline vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        res.reserve(105);
        preorder_traversal(root, res);
        return res;
    }
};

/// 迭代法
class Solution2 {
   public:
    inline vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        res.reserve(105);
        preorder_traversal2(root, res);
        return res;
    }
};

/// 迭代法2
class Solution3 {
   public:
    inline vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        res.reserve(105);
        preorder_traversal3(root, res);
        return res;
    }
};

int main() {
    TreeNode* root = to_tree({1, nullopt, 2});
    cout << Solution().preorderTraversal(root) << '\n';
    cout << Solution2().preorderTraversal(root) << '\n';
    cout << Solution3().preorderTraversal(root) << '\n';
    return 0;
}
