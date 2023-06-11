#include <ml>
using namespace std;

void func(random_access_iterator_tag) { cout << "random" << '\n'; }

void func(bidirectional_iterator_tag) { cout << "bi" << '\n'; }

int main() {
    // test move
    {
        vector<int> v = {1, 2, 3}, v2;
        v2 = mini_stl::move(v);
        cout << v << '\n';
        cout << v2 << '\n';
    }
    // test _iterator_category
    {
        vector<int> v = {1, 2, 3, 4, 5};
        list<int> l = {1, 2, 3, 4, 5};
        func(mini_stl::_iterator_category(v.begin()));
        func(mini_stl::_iterator_category(l.begin()));
    }
}