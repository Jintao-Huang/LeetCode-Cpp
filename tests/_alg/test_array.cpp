#include <leetcode>
using namespace leetcode;
int main() {
    {
        cout << euclidean_dist(1, 2, 3, 4) << '\n';
        cout << manhattan_dist(1, 2, 3, 4) << '\n';
    }
    //
    {
        vector<int> v = {1, 2}, v2;
        partial_sum_lc(v, v2);
        cout << v2 << '\n';
        v2.clear();
        v2.push_back(1);
        partial_sum_lc(v, v2);
        cout << v2 << '\n';
        v2.clear();
        v2.push_back(3);
        partial_sum_lc(v, v2, multiplies<>());
        cout << v2 << '\n';
    }
    {
        vector<vector<double>> vv = {{
                                         1,
                                         2,
                                         3,
                                     },
                                     {},
                                     {4, 5.3}};
        vector<double> res;
        res.reserve(get_vv_size(vv));
        flatten_vector(vv, res);
        cout << res << '\n';
    }
    return 0;
}
