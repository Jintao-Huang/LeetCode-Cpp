#ifndef _ALG_TREE_H
#define _ALG_TREE_H 1
#include <_lc/_lc_ds.h>
#include <_types.h>

namespace leetcode {

void preorder_traversal(TreeNode *root, vector<int> &res) {
    if (!root) {
        return;
    }
    res.push_back(root->val);
    preorder_traversal(root->left, res);
    preorder_traversal(root->right, res);
}

void inorder_traversal(TreeNode *root, vector<int> &res) {
    if (!root) {
        return;
    }
    inorder_traversal(root->left, res);
    res.push_back(root->val);
    inorder_traversal(root->right, res);
}

void postorder_traversal(TreeNode *root, vector<int> &res) {
    if (!root) {
        return;
    }
    postorder_traversal(root->left, res);
    postorder_traversal(root->right, res);
    res.push_back(root->val);
}

void preorder_traversal2(TreeNode *root, vector<int> &res) {
    if (!root) {
        return;
    }
    stack<TreeNode *> st;
    st.push(root);
    while (!st.empty()) {
        TreeNode *tn = st.top();
        st.pop();
        res.push_back(tn->val);
        if (tn->right) {
            st.push(tn->right);
        }
        if (tn->left) {
            st.push(tn->left);
        }
    }
}

void inorder_traversal2(TreeNode *root, vector<int> &res) {
    stack<TreeNode *> st;
    TreeNode *cur_tn = root;
    while (!st.empty() || cur_tn) {
        if (cur_tn) {
            st.push(cur_tn);
            cur_tn = cur_tn->left;
        } else {
            cur_tn = st.top();
            st.pop();
            res.push_back(cur_tn->val);
            cur_tn = cur_tn->right;
        }
    }
}

void postorder_traversal2(TreeNode *root, vector<int> &res) {
    if (!root) {
        return;
    }
    stack<TreeNode *> st;
    st.push(root);
    while (!st.empty()) {
        TreeNode *tn = st.top();
        st.pop();
        res.push_back(tn->val);
        if (tn->left) {
            st.push(tn->left);
        }
        if (tn->right) {
            st.push(tn->right);
        }
    }
    reverse(res.begin(), res.end());
}

void level_order_traversal(TreeNode *root, vector<vector<int>> &res) {
    if (!root) {
        return;
    }
    deque<TreeNode *> dq = {root};
    while (!dq.empty()) {
        int n = dq.size();
        vector<int> r(n);
        for (int i = 0; i < n; ++i) {
            TreeNode *parent = dq.front(), *lc = parent->left, *rc = parent->right;
            dq.pop_front();
            r[i] = parent->val;
            if (lc) {
                dq.push_back(lc);
            }
            if (rc) {
                dq.push_back(rc);
            }
        }
        res.push_back(move(r));
    }
}

}  // namespace leetcode

#endif