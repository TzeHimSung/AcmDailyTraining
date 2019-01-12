/* basic header */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <climits>
#include <cmath>
#include <cstdint>
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
/* namespace */
using namespace std;
/* header end */

int n,maxx=0,maxk=0,cnt=0;
const int maxn=2e5+10;
int a[maxn],u[maxn],v[maxn],head[maxn],nxt[2*maxn],endd[2*maxn],used[maxn],noUse[maxn];
vector<int> vec[maxn];

void addEdge(int a, int b)
{
    nxt[++cnt]=head[a];
    head[a]=cnt;
    endd[cnt]=b;
}

void dfs(int cur,int last,int depth)
{
    used[cur]=1;
    if (depth>maxx)
    {
        maxx=depth;
        maxk=cur;
    }
    for (int x=head[cur];x!=-1;x=nxt[x])
        if (endd[x]!=last && noUse[endd[x]])
            dfs(endd[x],cur,depth+1);
}

int main()
{
    init(head,-1);
    scanf("%d",&n);
    rep1(i,1,n)
    {
        scanf("%d",&a[i]);
        for (int j=2;j*j<=a[i];j++)
        {
            if (a[i]%j==0) vec[j].pb(i);
            while (a[i]%j==0) a[i]/=j;
        }
        if (a[i]!=1) 
            vec[a[i]].pb(i);
    }
    rep0(i,1,n)
    {
        int u,v; scanf("%d%d",&u,&v);
        addEdge(u,v); addEdge(v,u);
    }
    int res=0;
    rep1(i,1,200000)
    {
        rep0(j,0,vec[i].size()) noUse[vec[i][j]]=1;
        int ans=0;
        rep0(j,0,vec[i].size())
            if (!used[vec[i][j]] && noUse[vec[i][j]])
            {
                maxx=0;
                dfs(vec[i][j],0,1);
                dfs(maxk,0,1);
                ans=max(ans,maxx);
            }
        res=max(ans,res);
        rep0(j,0,vec[i].size())
            noUse[vec[i][j]]=used[vec[i][j]]=0;
    }
    printf("%d\n",res);
    return 0;
}