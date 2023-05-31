#include <leetcode>
using namespace leetcode;
int main() {
    const int N = 10000000;
    vector<int> v(N);
    auto it = v.begin() + 100;
    fill(v.begin(), it, 10);
    
    print(v.begin(), it, cout) << '\n';
    // print(v.data())
    ml::test_time([&v]() { fill(v.begin(), v.end(), 0); }, 10, 0);
    print(v.begin(), it, cout) << '\n';
    fill(v.begin(), v.begin() + 100, 10);
    print(v.begin(), it, cout) << '\n';
    //
    ml::test_time([&v]() { memset(v.data(), 0, sizeof(int)*N); }, 10, 0);
    print(v.begin(), it, cout) << '\n';
    return 0;
}
