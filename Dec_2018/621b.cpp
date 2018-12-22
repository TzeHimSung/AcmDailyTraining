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

const int maxn=2e3+10;
int n,f[maxn],s[maxn];

int main()
{
    scanf("%d",&n);
    init(f,0); init(s,0);
    while (n--)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        f[x+y]++;
        s[x-y+1000]++;
    }
    ll ans=0;
    rep1(i,0,2000)
    {
        ans+=f[i]*(f[i]-1)/2;
        ans+=s[i]*(s[i]-1)/2;
    }
    if (ans<0) ans=0;
    printf("%lld\n",ans);
    return 0;
}