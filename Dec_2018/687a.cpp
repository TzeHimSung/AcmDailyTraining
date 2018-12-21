//basic header
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <climits>
#include <cmath>
#include <cstdint>
//STL
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <array>
#include <iterator>
//define
#define int int32_t
#define ll int64_t
#define dou double
#define pb emplace_back
#define mp make_pair 
#define fir first
#define sec second
#define init(a,b) fill(begin(a),end(a),b)
#define sot(a,b) sort(a+1,a+1+b)
#define rep1(i,a,b) for(int i=a;i<=b;i++)
#define rep0(i,a,b) for(int i=a;i<b;i++)
#define repa(i,a) for(auto &i:a)
#define eps 1e-8
#define inf 0x3f3f3f3f
#define lson curr<<1
#define rson curr<<1|1
//namespace
using namespace std;
//header end

const int maxn=1e5+10;
vector<int>g[maxn],v[2];
int n,m,color[maxn];
bool sign=false;

void dfs(int curr,int col) /* currentPoint, color */
{
    if (color[curr]!=-1)
    {
        if (color[curr]!=col) sign=true; /* -1 */
        return;
    }
    color[curr]=col;
    v[col].pb(curr);
    repa(i,g[curr])
        dfs(i,col^1);
}

int main()
{
    init(color,-1);
    scanf("%d%d",&n,&m);
    rep1(i,1,m)
    {
        int u,v; scanf("%d%d",&u,&v);
        g[u].pb(v); g[v].pb(u);
    }
    rep1(i,1,n)
        if (color[i]==-1)
            dfs(i,0);
    if (sign)
        puts("-1");
    else
    {
        printf("%d\n",v[1].size());
        repa(i,v[1]) printf("%d ",i);
        puts("");
        printf("%d\n",v[0].size());
        repa(i,v[0]) printf("%d ",i);
        puts("");
    }
    return 0;
}