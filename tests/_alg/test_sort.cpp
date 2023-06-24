
#include <leetcode>
using namespace leetcode;

int main() {
    {
        vector<int> v = {4, 5, 2, 1, 9, 8, 4, 0, 7, 6};
        auto [it, it2] = three_way_partition(v.begin(), v.end(), 4);
        cout << it - v.begin() << ' ' << it2 - v.begin() << '\n';
        cout << v << '\n';
    }
    {
        vector<int> v = {4, 5, 2, 1, 9, 8, 4, 0, 7, 6};
        auto [it, it2] = three_way_partition(v.begin(), v.end(), 4, greater<>());
        cout << it - v.begin() << ' ' << it2 - v.begin() << '\n';
        cout << v << '\n';
    }
    cout << '\n';
    {
        vector<int> v = {4, 5, 2, 1, 9, 8, 0, 7, 6};
        quick_sort(v.begin(), v.end());
        cout << v << '\n';
        quick_sort(v.begin(), v.end(), greater<>());
        cout << v << '\n';
    }
    {
        vector<int> v = {4, 5, 2, 1, 9, 8, 0, 7, 6};
        quick_sort2(v.begin(), v.end());
        cout << v << '\n';
        quick_sort2(v.begin(), v.end(), greater<>());
        cout << v << '\n';
    }
    cout << '\n';
    {
        vector<int> v = {4, 5, 2, 1, 9, 8, 0, 7, 6};
        merge_sort(v.begin(), v.end());
        cout << v << '\n';
        merge_sort(v.begin(), v.end(), greater<>());
        cout << v << '\n';
    }
    {
        vector<int> v = {4, 5, 2, 1, 9, 8, 0, 7, 6};
        bubble_sort(v.begin(), v.end());
        cout << v << '\n';
        bubble_sort(v.begin(), v.end(), greater<>());
        cout << v << '\n';
    }
    {
        vector<int> v = {4, 5, 2, 1, 9, 8, 0, 7, 6};
        select_sort(v.begin(), v.end());
        cout << v << '\n';
        select_sort(v.begin(), v.end(), greater<>());
        cout << v << '\n';
    }
    {
        vector<int> v = {4, 5, 2, 1, 9, 8, 0, 7, 6};
        insert_sort(v.begin(), v.end());
        cout << v << '\n';
        insert_sort(v.begin(), v.end(), greater<>());
        cout << v << '\n';
    }
    {
        vector<int> v = {4, 5, 2, 1, 9, 8, 0, 7, 6};
        heap_sort(v.begin(), v.end());
        cout << v << '\n';
        heap_sort(v.begin(), v.end(), greater<>());
        cout << v << '\n';
    }
    {
        vector<int> v = {7, 6, 5, 4, 3, 2, 1, 2, 3, 4, 5, 6, 7};
        count_sort(v.begin(), v.end(), 0, 10);
        cout << v << '\n';
    }
}