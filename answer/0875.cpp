#include <leetcode>
using namespace leetcode;
class Solution {
   public:
    int minEatingSpeed(const vector<int>& piles, int h) {
        function<bool(int)> is_valid = [&piles, h](int mid) -> bool{
            int s = 0;
            double mid_d = static_cast<double>(mid);
            for (const int &p : piles) {
                //
                s += static_cast<int>(ceil(p / mid_d));
                if (s > h) {
                    return false;
                }
            }
            return true;
        };
        int piles_max = *max_element(piles.begin(), piles.end());
        return lower_bound_lc(1, piles_max, is_valid);
    }
};

int main() {
    vector<int> piles = {3, 6, 7, 11};
    int h = 8;
    cout << Solution().minEatingSpeed(piles, h) << '\n';
    return 0;
}