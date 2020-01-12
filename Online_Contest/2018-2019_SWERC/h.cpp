/* basic header */
#include <bits/stdc++.h>
/* define */
#define ll long long
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
using namespace std;

const int maxn = 1e5 + 10;
struct Node {
    int x, y, z, id, cnt;
    bool operator<(const Node &rhs)const {
        return x != rhs.x ? x < rhs.x : y != rhs.y ? y < rhs.y : z < rhs.z;
    }
} info[maxn], temp[maxn];
int n, m, num = 0, sum = 0, a[maxn], dis1[maxn], dis2[maxn], dis3[maxn], vis[maxn], head[maxn];
vector<pair<int, int>>g[maxn];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>q;

int lowbit(int x) {
    return x & -x;
}

void add(int pos, int val) {
    while (pos < maxn) a[pos] += val, pos += lowbit(pos);
}

int query(int pos) {
    int ret = 0;
    while (pos) ret += a[pos], pos -= lowbit(pos);
    return ret;
}

void dijkstra(int *dis, int st) {
    for (int i = 0; i <= n; ++i) dis[i] = int_inf;
    dis[st] = 0;
    while (q.size()) q.pop();
    q.push(mp(dis[st], st));
    while (q.size()) {
        pair<int, int> temp = q.top(); q.pop();
        if (temp.first > dis[temp.second]) continue;
        for (int i = 0; i < (int)g[temp.second].size(); ++i) {
            if (dis[temp.second] + g[temp.second][i].first < dis[g[temp.second][i].second]) {
                dis[g[temp.second][i].second] = dis[temp.second] + g[temp.second][i].first;
                q.push(mp(dis[g[temp.second][i].second], g[temp.second][i].second));
            }
        }
    }
}

void init() {
    for (int i = 0; i < maxn; i++) vis[i] = 0;
}

void cdq(int l, int r) {
    if (r - l <= 1) return;
    int mid = (r + l) >> 1;
    cdq(l, mid); cdq(mid, r);
    int lPtr = l, rPtr = mid, cnt = 0;
    while (lPtr < mid && rPtr < r) {
        if (info[lPtr].y <= info[rPtr].y) {
            add(info[lPtr].z, 1);
            temp[cnt++] = info[lPtr++];
        } else {
            int curr = query(info[rPtr].z);
            if (curr) vis[info[rPtr].id] = info[rPtr].cnt;
            temp[cnt++] = info[rPtr++];
        }
    }
    while (rPtr < r) {
        int curr = query(info[rPtr].z);
        if (curr) vis[info[rPtr].id] = info[rPtr].cnt;
        temp[cnt++] = info[rPtr++];
    }
    for (int i = l; i < lPtr; ++i) add(info[i].z, -1);
    while (lPtr < mid) temp[cnt++] = info[lPtr++];
    for (int i = 0; i < cnt; ++i) info[i + l] = temp[i];
}

int main() {
    scanf("%d%d", &n, &m); sum = n, num = 0;
    while (m--) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        g[u].pb(mp(w, v)); g[v].pb(mp(w, u));
    }
    // maintain distance
    dijkstra(dis1, 0); dijkstra(dis2, 1); dijkstra(dis3, 2);
    for (int i = 0; i < n; ++i)  info[i].x = dis1[i], info[i].y = dis2[i], info[i].z = dis3[i], head[++num] = info[i].z;
    sort(head + 1, head + 1 + num);
    // li san hua
    num = unique(head + 1, head + 1 + num) - head - 1;
    for (int i = 0; i < n; ++i) info[i].z = lower_bound(head + 1, head + 1 + num, info[i].z) - head;
    sort(info, info + n);
    int p = 1, tot = 0;
    // spj equal
    for (int i = 0; i < n; ++i) {
        if (info[i].x == info[i + 1].x && info[i].y == info[i + 1].y && info[i].z == info[i + 1].z) {
            p++; continue;
        }
        info[i].cnt = p; info[tot++] = info[i]; p = 1;
    }
    n = tot;
    for (int i = 0; i < n; ++i) info[i].id = i;
    cdq(0, n);
    for (int i = 0; i < n; ++i) sum -= vis[i];
    printf("%d\n", sum);
}
