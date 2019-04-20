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
#define pb push_back
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
//namespace
using namespace std;
//header end

const int maxn=3e5+10;
const int mod=998244353;
int color[maxn],t,n,m,sign;
ll ans,p1,p2;
vector<int>edge[maxn];

ll quickMod(ll a,ll b)
{
    ll res=1;
    while (b)
    {
        if (b&1) res=res*a%mod;
        b>>=1;
        a=a*a%mod;
    }
    return res;
}

void dfs(int u)
{
    if (color[u]==1) p1++; else p2++;
    rep0(i,0,edge[u].size())
    {
        int v=edge[u][i];
        if (!color[v])
        {
            if (color[u]==1) color[v]=2;
                else if (color[u]==2) color[v]=1;
            dfs(v);
        }
        else if (color[u]==color[v]) 
        {
            sign=0; return;
        }
    }
}

int main()
{
    scanf("%d",&t);
    while (t--)
    {
        sign=1; ans=1;
        scanf("%d%d",&n,&m);
        rep1(i,1,n) {edge[i].clear(); color[i]=0;}
        rep1(i,1,m)
        {
            int u,v; scanf("%d%d",&u,&v);
            edge[u].pb(v);
            edge[v].pb(u);
        }
        rep1(i,1,n)
            if (!color[i])
            {
                color[i]=1;
                p1=0,p2=0;
                dfs(i);
                ans=ans*((quickMod(2,p1)+quickMod(2,p2))%mod)%mod;
            }
        if (!sign) puts("0");
            else printf("%lld\n",ans);
    }
    return 0;
}