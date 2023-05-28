#include <leetcode>

class Solution {
   public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
        ListNode *dummy = new ListNode(), *p = dummy;
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val <= list2->val) {
                p->next = list1;
                list1 = list1->next;
            } else {
                p->next = list2;
                list2 = list2->next;
            }
            p = p->next;
        }
        p->next = list1 == nullptr ? list2 : list1;
        return dummy->next;
    }
};

int main() {
    ListNode *list1 = to_linkedlist({1, 2, 4});
    ListNode *list2 = to_linkedlist({1, 3, 4});
    ListNode *res = Solution().mergeTwoLists(list1, list2);
    vector<int> dst;
    from_linkedlist(res, dst);
    cout << dst << '\n';
}