
#include <leetcode>
using namespace std;

int main() {
    {
        int* p = malloc_c<int>(10);
        printf("%p\n", p);
        p = realloc_c<int>(p, 20);
        printf("%p\n", p);
        //
        memset_c(p, -1, 20);
        print(p, p + 20) << '\n';
        vector<int> v(20);
        memcpy_c(v.data(), p, 20);
        cout << v << '\n';
        fill(v.begin(), v.end(), 0);
        memmove_c(v.data(), p, 20);
        cout << v << '\n';
    }
}