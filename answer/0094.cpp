#include <leetcode>

class Solution {
   public:
    void _inorderTraversal(TreeNode *root, vector<int> &res) {
        if (root == nullptr) {
            return;
        }
        _inorderTraversal(root->left, res);
        res.push_back(root->val);
        _inorderTraversal(root->right, res);
    }
    inline vector<int> inorderTraversal(TreeNode *root) {
        vector<int> res;
        _inorderTraversal(root, res);
        return res;
    }
};

/// TODO: 迭代法
class Solution2 {};

int main() {
    vector<optional<int>> v = {1, nullopt, 2, 3};
    cout << v << '\n';
    TreeNode *root = to_tree(v);
    v.clear();
    from_tree(root, v);
    cout << v << '\n';
    cout << Solution().inorderTraversal(root) << '\n';
}