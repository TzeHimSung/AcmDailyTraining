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
    sum[u]=a[u]; //访问到的节点sum值必然没有赋值过
    repa(v,g[u]) //遍历当前节点的所有子节点
    {
        if (v==fa) continue;
        dfs1(v,u);
        sum[u]+=sum[v];
    }
}

void dfs2(int u, int fa, ll s)
{
    s=s-2*sum[u]+tot; //计算以当前节点为根的新ans值，更新答案
    //稍微想一下，新的答案就是s减去当前节点子树sum值，再加上所有节点权值和tot值，为了方便就写成-2*sum[u]+tot了
    ans=max(s,ans);
    repa(v,g[u]) //继续dfs遍历所有节点，这种做法相当于暴力枚举
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
        tot+=a[i]; //计算总节点权值，节点编号从1开始
    }
    rep0(i,1,n) //n-1条边
    {
        int u,v; scanf("%d%d",&u,&v);
        g[u].pb(v);
        g[v].pb(u);
    }
    dis[0]=-1; //0号节点到自己的距离是-1（不存在这个节点）
    dfs1(1,0); //dfs计算所有子树中根节点加该子树所有儿子节点的值
    rep1(i,1,n) //先算出以1号节点为根的值
        ans+=1LL*a[i]*dis[i];
    ll tmp=ans;
    repa(v,g[1])
        dfs2(v,1,tmp);
    printf("%lld\n",ans);
    return 0;
}
