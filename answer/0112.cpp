#include <leetcode>
using namespace leetcode;

class Solution {
   public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) {
            return false;
        }
        targetSum -= root->val;
        if (!root->left && !root->right) {
            return !targetSum;
        }
        return hasPathSum(root->left, targetSum) || hasPathSum(root->right, targetSum);
    }
};

int main() {
    TreeNode* root = to_tree({5, 4, 8, 11, nullopt, 13, 4, 7, 2, nullopt, nullopt, nullopt, 1});
    cout << Solution().hasPathSum(root, 22) << '\n';
}