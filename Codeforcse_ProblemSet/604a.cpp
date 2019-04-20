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

int p,q,m[6],w[6];
double ans=0;

int main()
{
    rep1(i,1,5) scanf("%d",&m[i]);
    rep1(i,1,5) scanf("%d",&w[i]);
    scanf("%d%d",&p,&q);
    rep1(i,1,5)
    {
        double x=500.0*i;
        ans+=max(0.3*x,(1-(double)m[i]/250.0)*x-50*(double)w[i]);
    }
    ans=ans+100*p-50*q;
    printf("%.f\n",ans);
    return 0;
}