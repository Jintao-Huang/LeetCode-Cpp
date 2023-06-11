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

    ///
    {
        vector<int> v = {1, 2, 3};
        cout << accumulate(v.begin(), v.end(), 0) << '\n';
        cout << accumulate(v.begin(), v.end(), 10, multiplies<>()) << '\n';
    }
    ///
    cout << '\n';
    {
        vector<int> v = {1, 2, 3}, v2;
        auto it = copy(v.begin(), v.end(), back_inserter(v2));
        cout << distance(v.begin(), v.end()) << '\n';
        cout << v2 << '\n';
    }
}
