#include <leetcode>
using namespace leetcode;

class Solution {
   public:
    inline ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0, head);
        ListNode* ln_pre = last_nth_node(&dummy, ++n);
        ln_pre->next = ln_pre->next->next;
        return dummy.next;
    }
};

/// 递归法
class Solution2 {
   public:
    inline ListNode* removeNthFromEnd(ListNode* head, int n) {
        int cur = 0;
        return remove_last_nth_node(head, n, cur);
    }
};

int main() {
    {
        vector<int> v = {1, 2, 3, 4, 5};
        ListNode* head = to_list(v);
        cout << Solution().removeNthFromEnd(head, 2) << '\n';
    }
    {
        vector<int> v = {1};
        ListNode* head = to_list(v);
        cout << Solution().removeNthFromEnd(head, 1) << '\n';
    }
    ///
    {
        vector<int> v = {1, 2, 3, 4, 5};
        ListNode* head = to_list(v);
        cout << Solution2().removeNthFromEnd(head, 2) << '\n';
    }
    {
        vector<int> v = {1};
        ListNode* head = to_list(v);
        cout << Solution2().removeNthFromEnd(head, 1) << '\n';
    }
}