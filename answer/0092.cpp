#include <leetcode>
using namespace leetcode;

class Solution {
   public:
    ListNode *reverseBetween(ListNode *head, int left, int right) {
        ListNode dummy(0, head), *first_prev = &dummy, *last = &dummy;
        right = right - left;
        while (--left) {
            first_prev = first_prev->next;
        }
        last = first_prev;
        right += 3;
        while (--right) {
            last = last->next;
        }
        first_prev->next = reverse_list(first_prev->next, last);
        return dummy.next;
    }
};

int main() {
    {
        vector<int> v = {1, 2, 3, 4, 5};
        ListNode *head = to_list(v);
        cout << Solution().reverseBetween(head, 2, 4) << '\n';
    }
    {
        vector<int> v = {5};
        ListNode *head = to_list(v);
        cout << Solution().reverseBetween(head, 1, 1) << '\n';
    }
}
