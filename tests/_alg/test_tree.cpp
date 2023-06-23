#include <leetcode>
using namespace leetcode;
int main() {
    // test 树的遍历
    {
        TreeNode *tn = to_tree({1, 2, 3, 4, nullopt, nullopt, 5});
        vector<int> res;
        preorder_traversal3(tn, res);
        cout << res << '\n';
        res.clear();
        postorder_traversal3(tn, res);
        cout << res << '\n';
    }

}