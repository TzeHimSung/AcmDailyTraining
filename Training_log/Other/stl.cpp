/* basic header */
#include <bits/stdc++.h>
/* define */
#define ll long long
#define pb emplace_back
#define mp make_pair
#define eps 1e-8
#define lson (curpos<<1)
#define rson (curpos<<1|1)
/* namespace */
using namespace std;
/* header end */

class A {
public:
    int a;
    A() {}
    explicit A(int _a): a(_a) {}
    virtual ~A() {}
    virtual void print() {
        cout << a << endl;
    }
};

int main() {
    A a = 10;
    a.print();
    return 0;
}