#include <leetcode>

int main() {
    vector<int> v = {1, 2, 3}, v2(v.size());
    stl::partial_sum(v.begin(), v.end(), v2.begin());
    cout << v2 << '\n';
    v2.clear();
    v2.resize(v.size());
    partial_sum(v.begin(), v.end(), v2.begin());
    cout << v2 << '\n';
    // 
    ostream_iterator<int> out(cout, ", ");
    stl::copy(v.begin(), v.end(), out);
    cout << '\n';
    copy(v.begin(), v.end(), out);
    cout << '\n';
    //
    cout << accumulate(v.begin(), v.end(), 1) << '\n';
    cout << accumulate(v.begin(), v.end(), 1, multiplies<>()) << '\n';
    cout << stl::accumulate(v.begin(), v.end(), 1) << '\n';
    cout << stl::accumulate(v.begin(), v.end(), 1, multiplies<>()) << '\n';
}
