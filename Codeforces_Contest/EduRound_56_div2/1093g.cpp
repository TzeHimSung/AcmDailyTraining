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

const int maxn=8e5+10;
struct segmentTree
{
    int mx[maxn],mn[maxn];

    void update(int curr, int l, int r, int pos, int val)
    {
        if (l==r)
        {
            mn[curr]=mx[curr]=val;
            return;
        }
        int mid=(l+r)>>1;
        if (pos<=mid) update(lson,l,mid,pos,val);
            else update(rson,mid+1,r,pos,val);
        mx[curr]=max(mx[lson],mx[rson]);
        mn[curr]=min(mn[lson],mn[rson]);
    }

    pair<int,int> query(int curr,int l,int r,int ql,int qr)
    {
        if (ql<=l && r<=qr) return mp(mx[curr],mn[curr]);
        int mid=(l+r)>>1,maxx=-inf,minn=inf;
        pair<int,int>tmp;
        if (ql<=mid)
        {
            tmp=query(lson,l,mid,ql,qr);
            maxx=max(maxx,tmp.fir);
            minn=min(minn,tmp.sec);
        }
        if (qr>mid)
        {
            tmp=query(rson,mid+1,r,ql,qr);
            maxx=max(maxx,tmp.fir);
            minn=min(minn,tmp.sec);
        }
        return mp(maxx,minn);
    }
}; 

segmentTree segt[16];
int n,k,m,kk,x[6],opt;

int main()
{
    scanf("%d%d",&n,&k); kk=(1<<(k-1))-1;
    //init
    rep1(i,0,kk)
        rep1(j,0,4*n)
        {
            segt[i].mn[j]=inf;
            segt[i].mx[j]=-inf;
        }
    rep1(i,1,n)
    {
        rep1(j,0,k-1) scanf("%d",&x[j]);
        rep1(j,0,kk)
        {
            int tmp=0;
            rep1(q,0,k-1)
                if (j&(1<<q)) tmp+=x[q];
                    else tmp-=x[q];
            segt[j].update(1,1,n,i,tmp);
        }
    }
    scanf("%d",&m);
    rep1(i,1,m)
    {
        scanf("%d",&opt);
        if (opt==2) //query
        {
            int l,r;
            scanf("%d%d",&l,&r);
            int ans=-inf;
            rep1(j,0,kk)
            {
                pair<int,int> tmp=segt[j].query(1,1,n,l,r);
                ans=max(ans,tmp.fir-tmp.sec);
                ans=max(ans,tmp.sec-tmp.fir);
            }
            printf("%d\n",ans);
        }
        else //signal point fix
        {
            int p;
            scanf("%d",&p);
            rep1(j,0,k-1) scanf("%d",&x[j]);
            rep1(j,0,kk)
            {
                int tmp=0;
                rep1(q,0,k-1)
                    if (j&(1<<q)) tmp+=x[q];
                        else tmp-=x[q];
                segt[j].update(1,1,n,p,tmp);
            }
        }
    }
    return 0;
}
