#ifndef _ALG_LINKEDLIST_H
#define _ALG_LINKEDLIST_H 1

#include <_lc/_lc_ds.h>
#include <_types.h>

namespace leetcode {
ListNode* merge_list(ListNode* list1, ListNode* list2) {
    ListNode *dummy = new ListNode(), *p = dummy;
    while (list1 && list2) {
        if (list1->val <= list2->val) {
            p->next = list1;
            list1 = list1->next;
        } else {
            p->next = list2;
            list2 = list2->next;
        }
        p = p->next;
    }
    p->next = list1 ? list1 : list2;
    return dummy->next;
}

ListNode* reverse_list(ListNode* first, ListNode* last = nullptr) {
    // [first, last)
    ListNode* res = last;
    while (first != last) {
        ListNode* _first_next = first->next;
        first->next = res;
        res = first;
        first = _first_next;
    }
    return res;
}

ListNode* middle_node(ListNode* first, ListNode* last = nullptr) {
    ListNode* slow = first;  // first: fast
    while (first != last && first->next != last) {
        slow = slow->next;
        first = first->next->next;
    }
    return slow;
}
}  // namespace leetcode

#endif