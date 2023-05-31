#include <leetcode>
using namespace leetcode;
int main(){
    vector<vector<double>> v= {{1, 2, 3.14}, {2.3, 4}};
    cout << v << '\n';
    vector<optional<int>> v2 = {1, 2, nullopt, 3};
    cout << v2 << '\n';
    array<int, 10> arr;
    cout << arr << '\n';
    deque<int> dq = {1, 2, 3};
    cout << dq << '\n';
    list<int> l = {1, 2, 3};
    cout << l << '\n';
    multiset<int> s = {1, 2, 3};
    cout << s << '\n';
    // 
    pair<string, int> p = {"hahaha", 1};
    cout<< p << '\n';
    unordered_set<string> us = {"python", "cpp", "c"};
    cout << us << '\n'; 
    unordered_map<string, int> um = {{"python", 1}, {"cpp", 2}, {"c", 3}};
    cout << um << '\n';
    //
    stack<int, vector<int>> st(vector<int>{1, 2, 3, 4});
    cout << st << '\n';
    queue<int> q(deque<int>{1, 2, 3, 4});
    cout << q << '\n';
    return 0;
}