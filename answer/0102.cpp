#include "pre.h"

class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> res;
        if (root == nullptr)
        {
            return res;
        }
        deque<TreeNode *> dq = {root};
        while (!dq.empty())
        {
            int n = dq.size();
            vector<int> r;
            while (n--)
            {
                TreeNode *parent = dq.front(), *lc = parent->left, *rc = parent->right;
                dq.pop_front();
                r.push_back(parent->val);
                if (lc != nullptr)
                {
                    dq.push_back(lc);
                }
                if (rc != nullptr)
                {
                    dq.push_back(rc);
                }
            }
            res.push_back(move(r));
        }
        return res;
    }
};

int main()
{
    vector<optional<int>> v = {3, 9, 20, nullopt, nullopt, 15, 7};
    TreeNode *root = to_tree(v);
    v.clear();
    from_tree(root, v);
    cout << v << '\n';
    cout << Solution().levelOrder(root) << '\n';
}
