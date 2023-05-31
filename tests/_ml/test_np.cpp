#include <leetcode>
using namespace leetcode;
int main() {
    vector<int> v = {1, 2, 3, 4};
    cout << ml::sum(v) << '\n';
    cout << ml::mean(v) << '\n';
    cout << ml::max(v) << '\n';
    cout << ml::min(v) << '\n';
    cout << ml::var(v) << '\n';
    cout << ml::std(v) << '\n';
    cout << '\n';
    vector<double> v2 = {1.1, 2, 3, 4.2};
    cout << ml::sum(v2) << '\n';
    cout << ml::mean(v2) << '\n';
    cout << ml::max(v2) << '\n';
    cout << ml::min(v2) << '\n';
    cout << ml::var(v2) << '\n';
    cout << ml::std(v2) << '\n';
    return 0;
}
