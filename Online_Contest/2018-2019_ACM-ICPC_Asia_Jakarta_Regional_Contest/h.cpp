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
struct Node {
    int l, r, c;
    Node() {}
    Node(int _l, int _r, int _c): l(_l), r(_r), c(_c) {}
    bool operator<(const Node &rhs)const {
        return l < rhs.l || (l == rhs.l && r < rhs.r);
    }
} que[MAXN];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
int n, m, qTop = 0, s = 0, a[MAXN], pre[MAXN], cnt0[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    pre[0] = cnt0[0] = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
        cnt0[i] = cnt0[i - 1] + (a[i] == 0 ? 1 : 0);
    }
    int flag = 1;
    for (int i = 0; i < m; i++) {
        int l, r, c;
        cin >> l >> r >> c;
        int tmp = pre[r] - pre[l - 1] + cnt0[r] - cnt0[l - 1] - c;
        if (tmp < 0) {
            cout << "Impossible" << endl;
            flag = 0;
        }
        que[i] = Node(l, r, tmp / 2);
    }
    if (!flag) return 0;
    sort(que, que + m);
    for (int i = 1; i <= n; i++) {
        while (qTop < m && que[qTop].l <= i) {
            pq.push(mp(que[qTop].c + s, que[qTop].r));
            qTop++;
        }
        while (pq.size() && pq.top().second < i) pq.pop();
        if (a[i]) continue;
        if (pq.empty() || pq.top().first > s) {
            s++, a[i] = -1;
        } else {
            a[i] = 1;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (i > 1) cout << " ";
        cout << a[i];
    }
    cout << endl;
    return 0;
}