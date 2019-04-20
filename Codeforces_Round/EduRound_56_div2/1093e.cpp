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
#define lson curr<<1
#define rson curr<<1|1
//namespace
using namespace std;
//header end

const int maxn=2e5+10;
int n,m,a[maxn],b[maxn],pos[maxn];
vector<int>f[maxn],val[maxn];

void addupdate(int x,int y)
{
    for (int i=x;i<maxn;i|=i+1)
        val[i].pb(y);
}

void addget(int x,int y)
{
    if (x<0 || y<0) return;
    for (int i=x;i>=0;i=(i&(i+1))-1)
        val[i].pb(y);
}

void update(int x,int y,int vals)
{
    for (int i=x;i<maxn;i|=i+1)
        for (int j=lower_bound(val[i].begin(),val[i].end(),y)-val[i].begin();j<int(f[i].size());j|=j+1)
            f[i][j]+=vals;
}

int get(int x, int y)
{
    if (x<0 || y<0) return 0;
    int re=0;
    for (int i=x;i>=0;i=(i&(i+1))-1)
        for (int j=lower_bound(val[i].begin(),val[i].end(),y)-val[i].begin();j>=0;j=(j&(j+1))-1)
            re+=f[i][j];
    return re;
}

struct Query
{
    int t,la,ra,lb,rb;
    Query(){};
}q[maxn];

int main()
{
    scanf("%d%d",&n,&m);
    rep0(i,0,n)
    {
        scanf("%d",&a[i]);
        pos[--a[i]]=i;
    }
    rep0(i,0,n)
    {
        scanf("%d",&b[i]);
        b[i]--;
        b[i]=pos[b[i]];
    }
    rep0(i,0,m)
    {
        scanf("%d",&q[i].t);
        if (q[i].t==1)
        {
            scanf("%d%d%d%d",&q[i].la,&q[i].ra,&q[i].lb,&q[i].rb);
            q[i].la--,q[i].ra--,q[i].lb--,q[i].rb--;
        }
        else
        {
            scanf("%d%d",&q[i].lb,&q[i].rb);
            q[i].lb--,q[i].rb--;
        }
    }
    vector<int>tmp(b,b+n);
    rep0(i,0,m)
    {
        if (q[i].t==1)
        {
            addget(q[i].rb,q[i].ra);
            addget(q[i].lb-1,q[i].ra);
            addget(q[i].rb,q[i].la-1);
            addget(q[i].lb-1,q[i].la-1);
        }
        else
        {
            addupdate(q[i].lb,b[q[i].lb]);
            addupdate(q[i].rb,b[q[i].rb]);
            swap(b[q[i].lb],b[q[i].rb]);
            addupdate(q[i].lb,b[q[i].lb]);
            addupdate(q[i].rb,b[q[i].rb]);
        }
    }
    rep0(i,0,n) b[i]=tmp[i];
    rep0(i,0,maxn)
    {
        sort(val[i].begin(),val[i].end());
        val[i].resize(unique(val[i].begin(),val[i].end())-val[i].begin());
        f[i].resize(val[i].size(),0);
    }
    rep0(i,0,n) update(i,b[i],1);
    rep0(i,0,m)
        if (q[i].t == 1)
        {
			int res = 0;
			res += get(q[i].rb, q[i].ra);
			res -= get(q[i].lb - 1, q[i].ra);
			res -= get(q[i].rb, q[i].la - 1);
			res += get(q[i].lb - 1, q[i].la - 1);
			printf("%d\n", res);
		}
		else
        {
			update(q[i].lb, b[q[i].lb], -1);
			update(q[i].rb, b[q[i].rb], -1);
			swap(b[q[i].lb], b[q[i].rb]);
			update(q[i].lb, b[q[i].lb], 1);
			update(q[i].rb, b[q[i].rb], 1);
		}
    return 0;
}