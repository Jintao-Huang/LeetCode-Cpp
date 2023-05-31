#include <leetcode>
using namespace leetcode;
int main() {
    vector<int> v = {1, 2, 3}, v2(v.size());
    partial_sum(v.begin(), v.end(), v2.begin());
    cout << v2 << '\n';
    v2.clear();
    partial_sum(v.begin(), v.end(), back_inserter(v2), multiplies<>());
    cout << v2 << '\n';
    v2.clear();
    v2.resize(v.size());
    mini_stl::partial_sum(v.begin(), v.end(), v2.begin());
    cout << v2 << '\n';
    v2.clear();
    mini_stl::partial_sum(v.begin(), v.end(), back_inserter(v2), multiplies<>());
    cout << v2 << '\n';
    cout << '\n';
    // 
    ostream_iterator<int> out(cout, ", ");
    mini_stl::copy(v.begin(), v.end(), out);
    cout << '\n';
    copy(v.begin(), v.end(), out);
    cout << '\n';
    cout << '\n';
    cout << '\n';
    //
    cout << accumulate(v.begin(), v.end(), 1) << '\n';
    cout << accumulate(v.begin(), v.end(), 1, multiplies<>()) << '\n';
    cout << mini_stl::accumulate(v.begin(), v.end(), 1) << '\n';
    cout << mini_stl::accumulate(v.begin(), v.end(), 1, multiplies<>()) << '\n';
    cout << '\n';
    // 
    cout << count(v.begin(), v.end(), 1) << '\n';
    cout << count_if(v.begin(), v.end(), bind(less_equal<>(), placeholders::_1, 2)) << '\n';
    cout << count_if(v.begin(), v.end(), bind(less_equal<>(), placeholders::_1, 2)) << '\n';
    cout << mini_stl::count(v.begin(), v.end(), 1) << '\n';
    cout << mini_stl::count_if(v.begin(), v.end(), bind(less_equal<>(), placeholders::_1, 2)) << '\n';
    cout << mini_stl::count_if(v.begin(), v.end(), bind(less_equal<>(), placeholders::_1, 2)) << '\n';
    cout << '\n';
    return 0;
}
