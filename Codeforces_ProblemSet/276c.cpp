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

const int maxn=2e5+10;
int a[maxn],c[maxn],n,m;
ll ans=0;

int main()
{
    init(c,0);
    scanf("%d%d",&n,&m);
    rep1(i,1,n) scanf("%d",&a[i]);
    while (m--)
    {
        int x,y; scanf("%d%d",&x,&y);
        c[x]++; c[y+1]--; //精妙,利用前缀和即可完美解决出现频率问题
    }
    rep1(i,1,n) c[i]+=c[i-1];
    sot(a,n); sot(c,n);
    rep1(i,1,n)
        ans+=(ll)a[i]*(ll)c[i];
    printf("%lld\n",ans);
    return 0;
}