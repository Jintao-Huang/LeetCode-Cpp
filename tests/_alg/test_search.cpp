#include <leetcode>
using namespace leetcode;
int main() {
    vector<int> v = {1, 2, 2, 2, 3};
    cout << bisect_left(v.begin(), v.end(), 2) - v.begin() << '\n';
    cout << bisect_right(v.begin(), v.end(), 2) - v.begin() << '\n';
    return 0;
}
