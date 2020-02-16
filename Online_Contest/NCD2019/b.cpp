#include<bits/stdc++.h>
using namespace std;

const int SIZE = 100010;
int head[SIZE], ver[SIZE * 2], Next[SIZE * 2];
int dfn[SIZE], low[SIZE];
int n, m, tot, num;
int color[SIZE];
int cnum = 0;
stack<int> st;
unordered_set<int> rds[SIZE];
void add(int x, int y) {
    ver[++tot] = y, Next[tot] = head[x], head[x] = tot;
}

void tarjan(int x, int in_edge) {
    dfn[x] = low[x] = ++num;
    st.push(x);
    for (int i = head[x]; i; i = Next[i]) {
        int y = ver[i];
        if (!dfn[y]) {
            tarjan(y, i);
            low[x] = min(low[x], low[y]);
        } else if (i != (in_edge ^ 1)) low[x] = min(low[x], dfn[y]);
    }
    if (low[x] == dfn[x]) {
        cnum++;
        while (!st.empty() && st.top() != x) {
            color[st.top()] = x;
            st.pop();
        }
        st.pop();
        color[x] = x;
    }
}
int furthest = 0;
int furthest_u = 0;
void dfs(int u, int f, int d) {
    if (d > furthest) {
        furthest_u = u;
        furthest = d;
    }
    for (auto v : rds[u]) {
        if (v == f) continue;
        dfs(v, u, d + 1);
    }
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &m);
        memset(head, 0, sizeof(head));
        memset(dfn, 0, sizeof(dfn));
        for (int i = 1; i <= n; ++i) rds[i].clear();
        tot = 1;
        cnum = 0;
        num = 0;
        for (int i = 1; i <= m; i++) {
            int x, y;
            scanf("%d%d", &x, &y);
            add(x, y), add(y, x);
        }
        for (int i = 1; i <= n; i++)
            if (!dfn[i]) tarjan(i, 0);
        for (int i = 2; i < tot; i += 2) {
            int u = color[ver[i]];
            int v = color[ver[i ^ 1]];
            if (u != v) {
                rds[u].insert(v);
                rds[v].insert(u);
            }
        }
        furthest = 0;
        furthest_u = 0;
        dfs(color[1], 0, 1);
        dfs(furthest_u, 0, 1);
        printf("%d\n", cnum - furthest);
    }
}