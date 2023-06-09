// Author: Jintao Huang
// Email: huangjintao@mail.ustc.edu.cn
// Date:

#ifndef _LC_IO_H
#define _LC_IO_H 1
#include <_io.h>
#include <_lc/_lc_ds.h>
#include <_lc/_lc_tools.h>
#include <_types.h>

namespace leetcode {
//
inline ostream &operator<<(ostream &out, ListNode *ln) {
    vector<int> res;
    from_list(ln, res);
    return out << res;
}
inline ostream &operator<<(ostream &out, TreeNode *tn) {
    vector<optional<int>> res;
    from_tree(tn, res);
    return out << res;
}

}  // namespace leetcode
#endif
