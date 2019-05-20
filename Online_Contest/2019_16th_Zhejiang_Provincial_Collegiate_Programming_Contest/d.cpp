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

struct Graph
{
    struct Vertex
    {
        vector<int>to;
        int inDeg, vis; //inDeg:入度
    };
    vector<Vertex>vertex;
    vector<int>eulerPath;
    Graph(int n): vertex(n) {}

    int dfs(int u, int dep)
    {
        vertex[u].vis = 1;
        eulerPath.pb(u);
        if (!dep) return 1;
        for (auto to : vertex[u].to)
            if (!vertex[to].vis)
            {
                int flag = 1;
                vertex[to].inDeg++;
                for (auto to : vertex[u].to)
                    if (!--vertex[to].inDeg && !vertex[to].vis) flag = 0;
                if (flag && dfs(to, dep - 1))
                    return 1;
                vertex[to].inDeg--;
                for (auto to : vertex[u].to) vertex[to].inDeg++;
            }
        //如果for一遍都没结果，说明不存在欧拉路
        eulerPath.pop_back();
        vertex[u].vis = 0;
        return 0;
    }
};

int main()
{
    int t; scanf("%d", &t);
    while (t--)
    {
        int n; scanf("%d", &n);
        Graph g(n + 1);
        for (int i = 1; i <= n; i++) //建图
            for (auto to :
                    {
                        i / 2, i - 1, i * 2, i * 2 + 1
                    })
                if (2 <= to && to <= n)
                    g.vertex[i].to.pb(to), g.vertex[to].inDeg++;
        if (!g.dfs(1, n - 1))
            puts("Impossible");
        else
            for (int i = 0; i < g.eulerPath.size(); i++)
                printf("%d%c", g.eulerPath[i], i < g.eulerPath.size() - 1 ? ' ' : '\n');
    }
    return 0;
}