// Author: Jintao Huang
// Email: huangjintao@mail.ustc.edu.cn
// Date:

#ifndef _LC_TOOLS_H
#define _LC_TOOLS_H 1

#include <_lc/_lc_ds.h>
#include <_types.h>

namespace leetcode {
template <typename Tp>
class MemoManager {
    /// RAII
   public:
    vector<Tp> buf;
    Tp create(Tp ptr) {
        buf.push_back(ptr);
        return ptr;
    }
    void clear() {
        for (int i = 0; i < buf.size(); ++i) {
            delete buf[i];
        }
    }
    ~MemoManager() { clear(); }
};
MemoManager<ListNode *> __ln_mm;
MemoManager<TreeNode *> __tn_mm;
ListNode *to_list(const vector<int> &v) {
    ListNode dummy, *p = &dummy;
    for (const int &x : v) {
        p->next = __ln_mm.create(new ListNode(x));
        p = p->next;
    }
    return dummy.next;
}

void from_list(ListNode *head, vector<int> &res) {
    while (head) {
        res.push_back(head->val);
        head = head->next;
    }
}

TreeNode *to_tree(const vector<optional<int>> &v) {
    int n = v.size();
    if (n == 0) {
        return nullptr;
    }
    TreeNode *root = __tn_mm.create(new TreeNode(v[0].value()));
    deque<TreeNode *> dq = {root};
    int i = 1;
    while (!dq.empty()) {
        TreeNode *parent = dq.front();
        dq.pop_front();
        //
        if (i >= n) {
            break;
        }
        const optional<int> &lc_x = v[i];
        ++i;
        if (lc_x.has_value()) {
            TreeNode *lc = __tn_mm.create(new TreeNode(lc_x.value()));
            dq.push_back(lc);
            parent->left = lc;
        }
        //
        if (i >= n) {
            break;
        }
        const optional<int> &rc_x = v[i];
        ++i;
        if (rc_x.has_value()) {
            TreeNode *rc = __tn_mm.create(new TreeNode(rc_x.value()));
            dq.push_back(rc);
            parent->right = rc;
        }
    }
    return root;
}

void from_tree(TreeNode *root, vector<optional<int>> &res) {
    if (!root) {
        return;
    }
    deque<TreeNode *> dq = {root};
    res.push_back(root->val);
    while (!dq.empty()) {
        TreeNode *parent = dq.front(), *lc = parent->left, *rc = parent->right;
        dq.pop_front();
        if (lc) {
            dq.push_back(lc);
            res.push_back(lc->val);
        } else {
            res.push_back(nullopt);
        }
        //
        if (rc) {
            dq.push_back(rc);
            res.push_back(rc->val);
        } else {
            res.push_back(nullopt);
        }
    }
    while (!res.back().has_value()) {
        res.pop_back();
    }
}
}  // namespace leetcode
#endif