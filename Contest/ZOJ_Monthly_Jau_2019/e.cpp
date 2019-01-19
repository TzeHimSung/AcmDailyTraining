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
// #define int 
#define ll long long 
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

const int maxn=30;
ll t,n,m,k,f[maxn],s[maxn],cnt=0,tot=1;

void calc(ll x)
{
    ll t=0;
    while (x)
    {
        s[++t]=x%10;
        x/=10;
        tot*=10;
    }tot/=10;
    rep1(i,1,t) f[i]=s[t-i+1];
    cnt+=t-1;
    for (int i=t;i>=1;i--)
    {
        ll sum=0;
        for (int j=1;j<=i;j++)
            if (j!=1) sum=sum*10+f[j];
                else sum=sum*10+f[j]-1;
                
        cnt+=sum;
    }
}

int main()
{
    cin>>t;
    while (t--)
    {
        init(f,0); init(s,0); cnt=0; tot=1;
        cin>>k>>m;
        calc(k);
        if (cnt>=m || (cnt<m-1 && k==tot))
        {
            puts("0");
            continue;
        }
        ll p=k-tot, c=k;
        while (cnt<m-1)
        {
            p*=10, c*=10, cnt+=p;                                                                                                                                                                                                                                                                                                                  
        }
        ll ans=max(c-cnt+m-2,k);
        printf("%lld\n",ans);
    }
    return 0;
}