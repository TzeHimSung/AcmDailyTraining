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
int t, n, deg[maxn];
map<int, set<int>>graph;
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
        if (deg[i.first] & 1) oddPoint.pb(i.first);
    }
    return ((!(int)oddPoint.size()) || ((int)oddPoint.size() == 2));
}

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        graph.clear();
        eulerPath.clear(); oddPoint.clear();
        scanf("%d", &n);
        rep1(i, 1, n) deg[i] = 0;
        rep1(i, 1, n)
        {
            if (i - 1 >= 1)
            {
                graph[i].insert(i - 1);
                deg[i]++, deg[i - 1]++;
            }
            if (2 * i <= n)
            {
                graph[i].insert(2 * i);
                deg[i]++, deg[2 * i]++;
            }
            if (2 * i + 1 <= n)
            {
                graph[i].insert(2 * i + 1);
                deg[i]++, deg[2 * i + 1]++;
            }
            if (i / 2 >= 1)
            {
                graph[i].insert(i / 2);
                deg[i]++, deg[i / 2]++;
            }
        }
        if (!checkEuler())
        {
            puts("-1");
            continue;
        }
        getEulerPath(oddPoint.empty() ? graph.begin()->first : oddPoint[0]);
        if ((int)eulerPath.size() != n)
        {
            puts("-1");
            continue;
        }
        int len = eulerPath.size();
        rep1(i, 0, len - 2) printf("%d ", eulerPath[i]);
        printf("%d\n", eulerPath[len - 1]);
    }
    return 0;
}