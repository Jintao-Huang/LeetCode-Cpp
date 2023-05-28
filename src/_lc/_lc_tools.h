#ifndef _LEETCODE_LC_TOOLS
#define _LEETCODE_LC_TOOLS 1

#include <_lc/_lc_ds.h>

ListNode *to_linkedlist(const vector<int> &v)
{
    ListNode *dummy = new ListNode(), *p = dummy;
    for (const int &x : v)
    {
        p->next = new ListNode(x);
        p = p->next;
    }
    return dummy->next;
}

void from_linkedlist(ListNode *&head, vector<int> &res)
{
    while (head != nullptr)
    {
        res.push_back(head->val);
        head = head->next;
    }
}

TreeNode *to_tree(const vector<optional<int>> &v)
{
    int n = v.size();
    if (n == 0)
    {
        return nullptr;
    }
    TreeNode *root = new TreeNode(v[0].value());
    deque<TreeNode *> dq = {root};
    int i = 1;
    while (!dq.empty())
    {
        TreeNode *parent = dq.front();
        dq.pop_front();
        //
        if (i >= n)
        {
            break;
        }
        const optional<int> &lc_x = v[i];
        if (lc_x.has_value())
        {
            TreeNode *lc = new TreeNode(lc_x.value());
            dq.push_back(lc);
            parent->left = lc;
        }
        ++i;
        //
        if (i >= n)
        {
            break;
        }
        const optional<int> &rc_x = v[i];
        if (rc_x.has_value())
        {
            TreeNode *rc = new TreeNode(rc_x.value());
            dq.push_back(rc);
            parent->right = rc;
        }
        ++i;
    }
    return root;
}

void from_tree(TreeNode *&root, vector<optional<int>> &res)
{
    if (root == nullptr)
    {
        return;
    }
    deque<TreeNode *> dq = {root};
    res.push_back(root->val);
    while (!dq.empty())
    {
        TreeNode *parent = dq.front(), *lc = parent->left, *rc = parent->right;
        dq.pop_front();
        if (lc == nullptr)
        {
            res.push_back(nullopt);
        }
        else
        {
            dq.push_back(lc);
            res.push_back(lc->val);
        }
        //
        if (rc == nullptr)
        {
            res.push_back(nullopt);
        }
        else
        {
            dq.push_back(rc);
            res.push_back(rc->val);
        }
    }
    while (!res.back().has_value())
    {
        res.pop_back();
    }
}
#endif // _LEETCODE_LC_TOOLS