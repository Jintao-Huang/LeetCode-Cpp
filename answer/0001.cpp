#include "pre.h"

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> mapper;
        int n = nums.size();
        for (int i = 0; i < n; ++i)
        {
            int x = nums[i], tmx = target - x; // minus
            if (mapper.count(tmx))
            {
                return {mapper[tmx], i};
            }
            //
            mapper[x] = i;
        }
        return {};
    }
};

int main()
{
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    cout << Solution().twoSum(nums, target) << '\n';
}