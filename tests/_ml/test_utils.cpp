#include <ml>
using namespace std;
int main() {
    const int N = 100000;
    vector<int> v(N);
    auto it = v.begin() + 100;
    fill(v.begin(), it, 10);
    // print(v.begin(), it) << '\n';
    println(v.begin(), it);
    // print(v.data())
    ml::test_time([&v]() { fill(v.begin(), v.end(), 0); }, 10, 0);
    println(v.begin(), it);
    fill(v.begin(), v.begin() + 100, 10);
    println(v.begin(), it);
    //
    ml::test_time([&v]() { memset(v.data(), 0, sizeof(char) * N); }, 10, 0);
    println(v.begin(), it);
    return 0;
    // time[number=10]: 0.000191±0.000009, min=0.000182, max=0.000215, len=10
    // time[number=10]: 0.000005±0.000000, min=0.000005, max=0.000006, len=10
}
