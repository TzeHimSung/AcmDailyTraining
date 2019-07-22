#include<bits/stdc++.h>

#define ll long long
using namespace std;
const int maxn = 105;
ll s[maxn];
bitset<100> bit[maxn];
int n, k;

struct node {
    bitset<100> now;
    int last = 0;
    ll val = 0;

    node(bitset<100> _now = 0, int _last = 0, ll _val = 0) {
        now = _now;
        last = _last;
        val = _val;
    }

    bool operator<(const node &c) const {
        return val > c.val;
    }
};

priority_queue<node> que;

ll dijkstra() {
    node st;
    st.now.reset();
    que.push(st);
    while (!que.empty()) {
        st = que.top();
        que.pop();
        if (--k == 0) {
            return st.val;
        }
        for (int i = st.last; i < n; ++i) {
            if (!st.now[i] && ((st.now & bit[i]) == st.now)) {
                st.now.set(i);
                que.push(node(st.now, i + 1, st.val + s[i]));
                st.now.reset(i);
            }
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    string str;
    for (int i = 0; i < n; ++i) cin >> s[i];
    for (int i = 0; i < n; ++i) {
        cin >> str;
        for (int j = 0; j < n; ++j) {
            if (str[j] == '1')bit[i].set(j);
            else bit[i].reset(j);
        }
    }
    cout << dijkstra() << endl;
    return 0;
}