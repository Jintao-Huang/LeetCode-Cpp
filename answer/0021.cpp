#include <leetcode>
using namespace leetcode;

class Solution {
   public:
    inline ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
        return merge_list(list1, list2);
    }
};

int main() {
    ListNode *list1 = to_list({1, 2, 4});
    ListNode *list2 = to_list({1, 3, 4});
    ListNode *res = Solution().mergeTwoLists(list1, list2);
    cout << res << '\n';
    return 0;
}