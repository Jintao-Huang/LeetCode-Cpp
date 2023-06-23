#include <leetcode>
using namespace leetcode;

class Solution {
   public:
    inline int maxDepth(TreeNode* root) { return tree_max_depth(root); }
};

int main() {
    TreeNode* root = to_tree({3, 9, 20, nullopt, nullopt, 15, 7});
    cout << Solution().maxDepth(root) << '\n';
}