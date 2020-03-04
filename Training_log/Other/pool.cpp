#include <boost/pool/pool.hpp>
// #include <boost/pool/object_pool.hpp>
#include <iostream>

using namespace std;

const int maxn = 10;

int main() {
    boost::pool<> p(sizeof(int));
    int *a[maxn];
    for (int i = 0; i < maxn; i++) {
        a[i] = static_cast<int *>(p.malloc());
        *a[i] = i;
        cout << *a[i] << endl;
    }
    for (int i = 0; i < maxn; i++) {
        p.free(a[i]);
        a[i] = nullptr;
    }
    return 0;
}