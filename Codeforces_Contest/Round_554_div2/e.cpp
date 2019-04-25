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
#define init(a,b) fill(begin(a),end(a),b)
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

const int maxn = 1e5 + 10;
int n, a[maxn], b[maxn];
map<int, multiset<int>>graph;
vector<int>eulerPath, oddPoint;

void getEulerPath(int u)
{
    while (graph[u].size())
    {
        int v = *graph[u].begin();
        graph[u].erase(graph[u].begin());
        graph[v].erase(graph[v].find(u));
        getEulerPath(v);
    }
    eulerPath.pb(u);
}

bool checkEuler()
{
    for (auto i : graph)
    {
        if ((int)i.second.size() & 1) oddPoint.pb(i.first);
    }
    return ((!(int)oddPoint.size()) || ((int)oddPoint.size() == 2));
}

int main()
{
    scanf("%d", &n);
    rep0(i, 1, n) scanf("%d", &a[i]);
    rep0(i, 1, n) scanf("%d", &b[i]);
    rep0(i, 1, n)
    {
        if (a[i] > b[i]) return puts("-1"), 0;
        graph[a[i]].insert(b[i]);
        graph[b[i]].insert(a[i]);
    }
    if (!checkEuler()) return puts("-1"), 0;
    getEulerPath(oddPoint.empty() ? graph.begin()->first : oddPoint[0]);
    if ((int)eulerPath.size() != n) return puts("-1"), 0;
    for (auto i : eulerPath) printf("%d ", i);
    puts("");
    return 0;
}