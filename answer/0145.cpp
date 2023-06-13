#include <leetcode>
using namespace leetcode;

/// 递归法
class Solution {
   public:
    inline vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        postorder_traversal(root, res);
        return res;
    }
};

/// 迭代法
class Solution2 {
   public:
    inline vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        postorder_traversal2(root, res);
        return res;
    }
};

/// 迭代法2
class Solution3 {
   public:
    inline vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        postorder_traversal3(root, res);
        return res;
    }
};

int main() {
    TreeNode* root = to_tree({1, nullopt, 2, 3});
    cout << Solution().postorderTraversal(root) << '\n';
    cout << Solution2().postorderTraversal(root) << '\n';
    cout << Solution3().postorderTraversal(root) << '\n';
    return 0;
}
