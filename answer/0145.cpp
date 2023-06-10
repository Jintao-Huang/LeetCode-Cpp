#include <leetcode>
using namespace leetcode;

class Solution {
   public:
    inline vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        res.reserve(105);
        postorder_traversal(root, res);
        return res;
    }
};

class Solution2 {
   public:
    inline vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        res.reserve(105);
        postorder_traversal2(root, res);
        return res;
    }
};

int main() {
    TreeNode* root = to_tree({1, nullopt, 2, 3});
    cout << Solution().postorderTraversal(root) << '\n';
    cout << Solution2().postorderTraversal(root) << '\n';
    return 0;
}
