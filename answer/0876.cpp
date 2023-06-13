#include <leetcode>
using namespace leetcode;

class Solution {
   public:
    inline ListNode* middleNode(ListNode* head) { return middle_node(head); }
};

int main() {
    ListNode* head = to_list({1, 2, 3, 4, 5, 6});
    cout << Solution().middleNode(head) << '\n';
}