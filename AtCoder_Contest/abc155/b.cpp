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

const int maxn = 110;
int n, a[maxn];

int main() {
    cin >> n;
    int flag = 1;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] & 1) continue;
        if (a[i] % 2 == 0 && (a[i] % 3 == 0 || a[i] % 5 == 0)) continue;
        else flag = 0;
    }
    if (flag) puts("APPROVED");
    else puts("DENIED");
    return 0;
}