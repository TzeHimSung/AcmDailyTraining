/* basic header */
#include <bits/stdc++.h>
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

int a, b, c, x = 0, y = 0, z = 0;

bool check(int x, int y, int z) {
    set<int>s; s.clear();
    while (x) {
        s.insert(x % 10);
        x /= 10;
    }
    while (y) {
        s.insert(y % 10);
        y /= 10;
    }
    while (z) {
        s.insert(z % 10);
        z /= 10;
    }
    if ((int)s.size() == 9 && !s.count(0)) return true;
    return false;
}

int main() {
    int flag = 0;
    scanf("%d%d%d", &a, &b, &c);
    while (x < 1000 && y < 1000 && z < 1000) {
        x += a, y += b, z += c;
        if (check(x, y, z)) {
            printf("%d %d %d\n", x, y, z);
            flag = 1;
        }
    }
    if (!flag) puts("No!!!");
    return 0;
}