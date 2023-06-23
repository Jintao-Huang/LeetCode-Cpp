#include <ml>
using namespace std;

int main() {
    {
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
        mini_stl::partial_sum(v.begin(), v.end(), back_inserter(v2), mini_stl::multiplies<>());
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
        cout << mini_stl::accumulate(v.begin(), v.end(), 1, mini_stl::multiplies<>()) << '\n';
        cout << '\n';
        //
        cout << count(v.begin(), v.end(), 1) << '\n';
        cout << count_if(v.begin(), v.end(), bind(less_equal<>(), placeholders::_1, 2)) << '\n';
        cout << count_if(v.begin(), v.end(), bind(less_equal<>(), placeholders::_1, 2)) << '\n';
        cout << mini_stl::count(v.begin(), v.end(), 1) << '\n';
        cout << mini_stl::count_if(v.begin(), v.end(),
                                   bind(mini_stl::less_equal<>(), placeholders::_1, 2))
             << '\n';
        cout << mini_stl::count_if(v.begin(), v.end(),
                                   bind(mini_stl::less_equal<>(), placeholders::_1, 2))
             << '\n';
        cout << '\n';
    }
    // test merge
    {
        vector<int> v = {1, 3, 5, 7, 9, 0, 2, 4, 6, 8};
        auto lo = v.begin(), mid = v.begin() + 5, hi = v.end();
        vector<int> v2;
        mini_stl::merge(lo, mid, mid, hi, back_inserter(v2));
        cout << v2 << '\n';
        vector<int> v3(15);
        auto it = mini_stl::merge(lo, mid, mid, hi, v3.begin());
        cout << it - v3.begin() << '\n';
        cout << v3 << '\n';
    }
    // test partition
    {
        list<int> v = {5, 1, 2, 3, 6, 7, 4};
        list<int>::iterator it =
            partition(v.begin(), --v.end(), bind(less<>(), placeholders::_1, v.back()));
        cout << distance(v.begin(), it) << '\n';
        cout << v << '\n';
    }
    {
        list<int> l = {5, 1, 2, 3, 6, 7, 4};
        list<int>::iterator it =
            mini_stl::partition(l.begin(), --l.end(), bind(less<>(), placeholders::_1, l.back()));
        cout << distance(l.begin(), it) << '\n';
        cout << l << '\n';
    }
    {
        forward_list<int> fl = {5, 1, 2, 3, 6, 7, 4};
        forward_list<int>::iterator it =
            mini_stl::partition(fl.begin(), fl.end(), bind(less<>(), placeholders::_1, 4));
        cout << distance(fl.begin(), it) << '\n';
        cout << fl << '\n';
    }
    ///
    cout << '\n';
    {
        vector<int> v = {1, 2, 2, 3, 4, 4, 5, 5};
        cout << adjacent_find(v.begin(), v.end()) - v.begin() << '\n';  // 1
        int n = unique(v.begin(), v.end()) - v.begin();
        cout << n << '\n';  // 5
        cout << v << '\n';
        // [1, 2, 3, 4, 5, 4, 5, 5]  // 4, 5, 5 无效内容, 不是swap, 是覆盖.
        v.resize(n);
        cout << v << '\n';
        // [1, 2, 3, 4, 5]
    }
    {
        vector<int> v = {1, 2, 3, 4, 5};
        cout << adjacent_find(v.begin(), v.end()) - v.begin() << '\n';  // 5
        cout << unique(v.begin(), v.end()) - v.begin() << '\n';         // 5
        cout << v << '\n';
        // [1, 2, 3, 4, 5]
    }
    ///
    cout << '\n';
    {
        vector<int> v = {1, 2, 2, 3, 4, 4, 5, 5};
        cout << mini_stl::adjacent_find(v.begin(), v.end()) - v.begin() << '\n';  // 1
        int n = mini_stl::unique(v.begin(), v.end()) - v.begin();
        cout << n << '\n';  // 5
        cout << v << '\n';
        // [1, 2, 3, 4, 5, 4, 5, 5]  // 4, 5, 5 无效内容, 不是swap, 是覆盖.
        v.resize(n);
        cout << v << '\n';
        // [1, 2, 3, 4, 5]
    }
    {
        vector<int> v = {1, 2, 3, 4, 5};
        cout << mini_stl::adjacent_find(v.begin(), v.end()) - v.begin() << '\n';  // 5
        cout << mini_stl::unique(v.begin(), v.end()) - v.begin() << '\n';         // 5
        cout << v << '\n';
        // [1, 2, 3, 4, 5]
    }
    cout << '\n';
    {
        int x = 1, y = 2;
        mini_stl::iter_swap(&x, &y);
        cout << x << ' ' << y << '\n';
    }
    ///
    {
        vector<int> v = {1, 2, 3, 4, 5};
        mini_stl::reverse(v.begin(), v.end());
        cout << v << '\n';

        vector<int> l = {1, 2, 3, 4, 5};
        mini_stl::reverse(l.begin(), l.end());
        cout << l << '\n';
    }
    ///
    {
        vector<int> v = {4, 1, 2, 3, 4, 5};
        cout << *mini_stl::min_element(v.begin(), v.end()) << '\n';
        cout << *min_element(v.begin(), v.end()) << '\n';
    }
    /// heap
    cout << '\n';
    {
        vector<int> v = {1, 3, 5, 6, 8, 9};
        mini_stl::make_heap(v.begin(), v.end());
        cout << v << '\n';
        sort_heap(v.begin(), v.end());
        cout << v << '\n';
    }
    //
    {
        vector<int> v = {1, 3, 5, 6, 8, 9};
        cout << v << '\n';
        mini_stl::make_heap(v.begin(), v.end());
        cout << v << '\n';
        //
        v.push_back(10);
        mini_stl::push_heap(v.begin(), v.end());
        cout << v << '\n';
        mini_stl::pop_heap(v.begin(), v.end());
        cout << v.back() << '\n';
        v.pop_back();
        cout << v << '\n';
    }
}
