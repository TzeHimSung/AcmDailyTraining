/* basic header */
#include <bits/stdc++.h>
/* define */
#define ll long long
#define ull unsigned long long
#define dou double
#define pb emplace_back
#define mp make_pair
#define sot(a,b) sort(a+1,a+1+b)
#define eps 1e-8
#define int_inf 0x3f3f3f3f
#define ll_inf 0x7f7f7f7f7f7f7f7f
#define lson (curpos<<1)
#define rson (curpos<<1|1)
/* namespace */
using namespace std;
/* header end */

const int maxn = 4e4 + 10;
const int x = 123;
int n, m, _rank[maxn];
char str[maxn];
ull h[maxn], xp[maxn], _hash[maxn];

void init() {
    h[n] = 0;
    for (int i = n - 1; i >= 0; i--) h[i] = h[i + 1] * x + str[i] - 'a';
    xp[0] = 1;
    for (int i = 1; i <= n; i++) xp[i] = xp[i - 1] * x;
}

bool cmp(const int &a, const int &b) {
    return _hash[a] < _hash[b] || (_hash[a] == _hash[b] && a < b);
}

int possible(int curLen) {
    int cnt, pos = -1;
    for (int i = 0; i < n - curLen + 1; i++) {
        _rank[i] = i;
        _hash[i] = h[i] - h[i + curLen] * xp[curLen];
    }
    sort(_rank, _rank + n - curLen + 1, cmp);
    for (int i = 0; i < n - curLen + 1; i++) {
        if (!i || _hash[_rank[i]] != _hash[_rank[i - 1]]) cnt = 0;
        if (++cnt >= m) pos = max(pos, _rank[i]);
    }
    return pos;
}

int main() {
    while (scanf("%d", &m) == 1 && m) {
        scanf("%s", str);
        n = strlen(str);
        init();
        if (possible(1) == -1) {
            puts("none");
            continue;
        }
        int l = 1, r = n + 1;
        while (l + 1 < r) {
            int mid = l + (r - l) / 2;
            if (possible(mid) != -1) l = mid;
            else r = mid;
        }
        int pos = possible(l);
        printf("%d %d\n", l, pos);
    }
    return 0;
}

