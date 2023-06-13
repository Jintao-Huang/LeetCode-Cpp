#include <leetcode>
using namespace leetcode;

class Solution {
   public:
    inline ListNode* reverseList(ListNode* head) { return reverse_list(head, nullptr); }
};

int main() {
    ListNode* head = to_list({1, 2, 3, 4, 5});
    cout << Solution().reverseList(head) << '\n';
}