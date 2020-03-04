#include <boost/pool/pool.hpp>
#include <boost/pool/object_pool.hpp>
#include <iostream>

using namespace std;

const int maxn = 10;

class A {
public:
    int a;
    A() {
        a = 0;
    }
    ~A() {}
};

int main() {
    boost::pool<> p(sizeof(int));
    boost::object_pool<A> q;
    int *num[maxn];
    A *a[maxn];
    // call pool
    for (int i = 0; i < maxn; i++) {
        num[i] = static_cast<int *>(p.malloc());
        *num[i] = i;
        cout << *num[i] << endl;
    }
    for (int i = 0; i < maxn; i++) {
        p.free(num[i]);
        num[i] = nullptr;
    }
    // call object pool
    for (int i = 0; i < maxn; i++) {
        a[i] = q.construct();
        cout << i << "! ";
    }
    cout << endl;
    for (int i = 0; i < maxn; i++) {
        q.destroy(a[i]);
        cout << i << "! ";
    }
    cout << endl;
    return 0;
}