#include <leetcode>
using namespace leetcode;

class Solution {
   public:
    inline bool isSameTree(TreeNode *p, TreeNode *q) { return is_same_tree(p, q); }
};

int main() {
    {
        TreeNode *root1 = to_tree({1, 2, 3});
        TreeNode *root2 = to_tree({1, 2, 3});
        cout << Solution().isSameTree(root1, root2) << '\n';
    }
    {
        TreeNode *root1 = to_tree({1, 2});
        TreeNode *root2 = to_tree({1, nullopt, 2});
        cout << Solution().isSameTree(root1, root2) << '\n';
    }
}