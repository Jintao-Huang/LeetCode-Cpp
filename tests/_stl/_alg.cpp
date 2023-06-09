#include <_io.h>
#include <bits/stdc++.h>
using namespace std;

int main() {
    // ref: https://cplusplus.com/reference/
    ///
    {
        vector<int> v = {1, 2, 3}, v2;
        partial_sum(v.begin(), v.end(), back_inserter(v2));
        cout << v2 << '\n';
        //
        v2.clear();
        partial_sum(v.begin(), v.end(), back_inserter(v2), multiplies<>());
        cout << v2 << '\n';
    }

    /// test accumulate
    {
        vector<int> v = {1, 2, 3};
        cout << accumulate(v.begin(), v.end(), 0) << '\n';
        cout << accumulate(v.begin(), v.end(), 10, multiplies<>()) << '\n';
    }
    /// test copy 
    cout << '\n';
    {
        vector<int> v = {1, 2, 3}, v2;
        auto it = copy(v.begin(), v.end(), back_inserter(v2));
        cout << distance(v.begin(), v.end()) << '\n';
        cout << v2 << '\n';
    }
    {
        vector<int> v = {1, 2, 3}, v2(3);  // memmove优化
        auto it = copy(v.begin(), v.end(), v2.begin());
        cout << distance(v.begin(), v.end()) << '\n';
        cout << v2 << '\n';
    }
    // test fill
    {
        vector<bool> v(10);              // 1bit 每个元素
        fill(v.begin(), v.end(), '\1');  // 没有memset优化.
        //
        vector<char> v2(10);  // memset优化.
        printf("%p\n", v2.data());
        cout << v2.size() << '\n';
        fill(v2.begin(), v2.end(), '\1');  // memset优化.
    }
    cout << '\n';
    // test adjacent_find, unique
        {
        vector<int> v = {1, 2, 2, 3, 4, 4, 5, 5};
        cout << adjacent_find(v.begin(), v.end()) - v.begin() << '\n';  // 1
        int n = unique(v.begin(), v.end()) - v.begin();
        cout << n << '\n';         // 5
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
    //
    
}
