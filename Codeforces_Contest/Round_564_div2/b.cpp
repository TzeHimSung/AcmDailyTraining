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
#define lson curpos<<1
#define rson curpos<<1|1
/* namespace */
using namespace std;
/* header end */

int n;

int main() {
    cin >> n;
    int ans = 0;
    for (ans = 1;; ans++) {
        if (ans + ans - 1 - 1 >= n - 1) break;
    }
    int cnt = n / 2, cx, cy;
    for (int i = 1; i <= ans; i++) {
        for (int j = 1; j <= ans; j++) {
            cout << i << " " << j << endl;
            cnt--;
            if (!cnt) {
                cx = ans - i + 1; cy = ans - j + 1;
                goto mark;
            }
        }
    }
mark:;
    cnt = n / 2;
    while (cnt) {
        cout << cx << " " << cy << endl;
        cy++, cnt--;
        if (cy > ans) cy = 1, cx++;
    }
    return 0;
}