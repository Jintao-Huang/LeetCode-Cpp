#include <leetcode>
using namespace leetcode;
int main() {
    vector<int> v = {1, 2, 2, 2, 3};
    cout << bisect_left(v, 2) << '\n';
    cout << bisect_right(v, 2) << '\n';
    return 0;
}
