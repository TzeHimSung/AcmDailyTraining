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

const int MAXN = 1e5 + 10;
int n, m, b[MAXN], f[MAXN];
ll fwt[MAXN], curNum = 0, ans = 0;

struct Person {
    int b, f;
    ll d;
    bool operator<(const Person &rhs) const {
        return b == rhs.b ? f > rhs.f : b < rhs.b;
    }
} person[MAXN];

int lowbit(int x) {
    return x & -x;
}

void update(int pos, ll val) {
    while (pos <= m) {
        fwt[pos] = max(fwt[pos], val);
        pos += lowbit(pos);
    }
}

ll query(int pos) {
    ll ans = 0;
    while (pos > 0) {
        ans = max(ans, fwt[pos]);
        pos -= lowbit(pos);
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> person[i].b >> person[i].f >> person[i].d;
        f[i] = person[i].f;
    }
    sort(person + 1, person + 1 + n);
    sort(f + 1, f + 1 + n);
    m = unique(f + 1, f + 1 + n) - f - 1;
    for (int i = 1; i <= n; i++) {
        int pos = lower_bound(f + 1, f + 1 + m, person[i].f) - f;
        if (person[i].b == person[i - 1].b && person[i].f == person[i - 1].f) curNum += person[i].d;
        else curNum = query(pos - 1) + person[i].d;
        ans = max(ans, curNum);
        update(pos, curNum);
    }

    cout << ans << endl;
    return 0;
}