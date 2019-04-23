/* basic header */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <cmath>
#include <cstdint>
#include <climits>
#include <float.h>
/* STL */
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <array>
#include <iterator>
/* define */
#define ll long long
#define dou double
#define pb emplace_back
#define mp make_pair
#define fir first
#define sec second
#define sot(a,b) sort(a+1,a+1+b)
#define rep1(i,a,b) for(int i=a;i<=b;++i)
#define rep0(i,a,b) for(int i=a;i<b;++i)
#define repa(i,a) for(auto &i:a)
#define eps 1e-8
#define int_inf 0x3f3f3f3f
#define ll_inf 0x7f7f7f7f7f7f7f7f
#define lson curPos<<1
#define rson curPos<<1|1
/* namespace */
using namespace std;
/* header end */

const int maxn = 1e2 + 10;
const int maxm = 5e3 + 10;
ll tol, head[maxn], Q[maxn], dep[maxn], cur[maxn], sta[maxn];
int n, m, s, t, S[maxn];

struct Edge
{
    ll cap, flow;
    int to, next;
} edge[maxm];

void init()
{
    tol = 2;
    memset(head, -1, sizeof(head));
}

void addEdge(int u, int v, ll w, ll rw = 0)
{
    edge[tol].to = v; edge[tol].cap = w; edge[tol].flow = 0;
    edge[tol].next = head[u]; head[u] = tol++;
    edge[tol].to = u; edge[tol].cap = rw; edge[tol].flow = 0;
    edge[tol].next = head[v]; head[v] = tol++;
}

bool bfs(int start, int end)
{
    for (int i = 1; i <= n; i++) dep[i] = -1, gap[i] = 0;
    gap[0] = 1;
    int front = 0, rear = 0;
    dep[end] = 0;
    Q[rear++] = end;
    while (front != end)
    {
        int u = Q[front++];
        for (int i = head[u]; i != -1; i = edge[i].next)
        {
            int v = edge[i].to;
            if (dep[v] != -1) continue;
            Q[rear++] = v;
            dep[v] = dep[u] + 1;
            gap[dep[v]]++;
        }
    }
}

int sap(int start, int end, int N)
{
    bfs(start, end);
    memcpy(cur, head, sizeof(head));

}

int main()
{
    scanf("%d%d%d%d", &n, &m, &s, &t);
    init();
    rep1(i, 1, m)
    {
        int u, v; ll c; scanf("%d%d%lld", &u, &v, &c);
        addEdge(u, v, c);
    }
    printf("%lld\n", dinic(s, t, n));
    return 0;
}