#include <ml>
using namespace leetcode;
int main() {
    constexpr int N = 1000000;
    vector<int> v(N), v2(N);
    fill(v.begin(), v.end(), 1);
    ml::test_time([&v, &v2]() { memmove_c(v2.data(), v.data(), N); }, 100);
    ml::test_time([&v, &v2]() { memcpy_c(v2.data(), v.data(), N); }, 100);
    print(v2.begin(), v2.begin() + 100);
    // time[number=100]: 0.000122±0.000011, min=0.000117, max=0.000188, len=100
    // time[number=100]: 0.000151±0.000023, min=0.000118, max=0.000233, len=100
}