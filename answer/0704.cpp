#include <leetcode>

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        vector<int>::iterator it = lower_bound(nums.begin(), nums.end(), target);
        if (it == nums.end() || *it != target)
        {
            return -1;
        }
        else
        {
            return distance(nums.begin(), it);
        }
    }
};

int main()
{
    vector<int> nums = {-1, 0, 3, 5, 9, 12};
    cout << Solution().search(nums, 9) << '\n';
}