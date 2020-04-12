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

const int MAXN = 1e3 + 10;
int n, a[MAXN], b[MAXN];
int top1 = 0, top2 = 0, p1 = 0, p2 = 0;
struct Node {
    int index, delta;
    Node() {}
    Node(int _idx, int _del): index(_idx), delta(_del) {}
} st1[MAXN], st2[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    for (int i = 1; i <= n; i++) {
        int delta = a[i] - b[i];
        if (delta > 0)
            st1[top1++] = Node(i, delta);
        else
            st2[top2++] = Node(i, delta);
    }
    while (p1 < top1) {
        auto curr = st1[p1++];
        int index = curr.index, delta = curr.delta;
        while (delta) {
            auto t = st2[p2];
            int tmp = min(delta, -t.delta);
            if (tmp) cout << index << " " << t.index << " " << tmp << endl;
            delta -= tmp;
            st2[p2].delta += tmp;
            if (!st2[p2].delta) p2++;
        }
    }
    return 0;
}