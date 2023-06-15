// Author: Jintao Huang
// Email: huangjintao@mail.ustc.edu.cn
// Date:

#ifndef _ALG_BST_H
#define _ALG_BST_H 1
#include <_lc/_lc_ds.h>
#include <_types.h>
namespace leetcode {
TreeNode* search_bst_node(TreeNode* root, int val) {
    while (root) {
        if (val < root->val) {
            root = root->left;
        } else if (val > root->val) {
            root = root->right;
        } else {
            return root;
        }
    }
    return nullptr;
}
}  // namespace leetcode

#endif