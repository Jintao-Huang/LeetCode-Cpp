#include <ml>
using namespace std;
int main() {
    const int N = 10000000;
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
    ml::test_time([&v]() { memset(v.data(), 0, sizeof(int)*N); }, 10, 0);
    println(v.begin(), it);
    return 0;
}
