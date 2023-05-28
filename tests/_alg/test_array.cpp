#include <leetcode>

int main() {
    cout << euclidean_dist(1, 2, 3, 4) << '\n';
    cout << manhattan_dist(1, 2, 3, 4) << '\n';
    //
    vector<int> v = {1, 2}, v2;
    partial_sum_lc(v, v2);
    cout << v2 << '\n';
    v2.clear();
    partial_sum_lc(v, v2, 0);
    cout << v2 << '\n';
    v2.clear();
    partial_sum_lc(v, v2, 1, multiplies<>());
    cout << v2 << '\n';
    //
}
