//basic
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

const int maxn=2e5+10;
int n,a[maxn],dis[maxn];
ll sum[maxn],ans=0,tot=0;
vector<int>g[maxn];

void dfs1(int u, int fa)
{
    dis[u]=dis[fa]+1;
    sum[u]=a[u];
    repa(v,g[u])
    {
        if (v==fa) continue;
        dfs1(v,u);
        sum[u]+=sum[v];
    }
}

void dfs2(int u, int fa, ll s)
{
    s=s-2*sum[u]+tot;
    ans=max(s,ans);
    repa(v,g[u])
    {
        if (v==fa) continue;
        dfs2(v,u,s);
    }
}

int main()
{
    scanf("%d",&n);
    rep1(i,1,n)
    {
        scanf("%d",&a[i]);
        tot+=a[i];
    }
    rep0(i,1,n)
    {
        int u,v; scanf("%d%d",&u,&v);
        g[u].pb(v);
        g[v].pb(u);
    }
    dis[0]=-1;
    dfs1(1,0);
    rep1(i,1,n)
        ans+=1LL*a[i]*dis[i];
    ll tmp=ans;
    repa(v,g[1])
        dfs2(v,1,tmp);
    printf("%lld\n",ans);
    return 0;
}
