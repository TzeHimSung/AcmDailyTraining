/* basic header */
#include <bits/stdc++.h>
#include <random>
/* define */
#define ll long long
#define dou double
#define pb emplace_back
#define mp make_pair
#define sot(a,b) sort(a+1,a+1+b)
#define rep1(i,a,b) for(int i=a;i<=b;++i)
#define rep0(i,a,b) for(int i=a;i<b;++i)
#define eps 1e-8
#define int_inf 0x3f3f3f3f
#define ll_inf 0x7f7f7f7f7f7f7f7f
#define lson (curpos<<1)
#define rson (curpos<<1|1)
/* namespace */
using namespace std;
/* header end */

mt19937 rnd(time(0));

int main() {
    freopen("input", "w", stdout);
    int n = rnd() % 30 + 1;
    cout << n << endl;
    for (int i = 1; i <= n; i++) {
        int x = rnd() % 100 + 1, y = rnd() % 100 + 1;
        cout << x << " " << y << endl;
    }
    return 0;
}