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

const int mod=998244353;
int n;
const int maxn=1e6+10;
ll a[maxn],p[maxn];

int main()
{
    scanf("%d",&n);
    if (n==1)
        puts("1");
    else if (n==2)
        puts("2");
    else if (n==3)
        puts("9");
    else
    {
        a[1]=a[2]=1,a[3]=3; p[3]=6;
        for (int i=4;i<=n;i++)
        {
            a[i]=(a[i-1]*(i-1)+1)%mod;
            p[i]=(p[i-1]*i)%mod;
        }
        printf("%d\n",(p[n]-a[n]+2*mod)%mod*n%mod);
    }
    return 0;
}