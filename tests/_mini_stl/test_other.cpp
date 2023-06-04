#include <ml>
using namespace std;

int main() {
    vector<int> v = {1, 2, 3}, v2;
    v2 = mini_stl::move(v);
    cout << v << '\n';
    cout << v2 << '\n';
}