/* basic header */
#include <bits/stdc++.h>
/* define */
#define ll long long
#define dou double
#define pb emplace_back
#define mp make_pair
#define sot(pos,b) sort(pos+1,pos+1+b)
#define rep1(i,pos,b) for(int i=pos;i<=b;++i)
#define rep0(i,pos,b) for(int i=pos;i<b;++i)
#define eps 1e-8
#define int_inf 0x3f3f3f3f
#define ll_inf 0x7f7f7f7f7f7f7f7f
#define lson curpos<<1
#define rson curpos<<1|1
/* namespace */
using namespace std;
/* header end */

const int maxn = 2e5 + 10;
int n, pos[maxn], x, flag = 0;

int main() {
    scanf("%d", &n);
    rep1(i, 1, n) scanf("%d", &x);
    rep1(i, 1, n) {
        scanf("%d", &x);
        if (x > 0) pos[x] = i; // record sequence
        if (x == 1) flag = 1; // start sign
        else {
            if (flag && x == flag + 1) flag++; // start and in increasing order
            else flag = 0;
        }
    }
    if (flag) {  // special judge
        int flag2 = 1;
        rep1(i, flag + 1, n)
        if (pos[i] >= i - flag) flag2 = 0;
        if (flag2) {
            return printf("%d\n", n - flag), 0;
        }
    }
    int tmp = 0;
    rep1(i, 1, n) tmp = max(tmp, pos[i] - i + 1);
    printf("%d\n", n + tmp);
    return 0;
}