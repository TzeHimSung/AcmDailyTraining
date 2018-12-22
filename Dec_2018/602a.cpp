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

int n,bx,by,m;
ll val1=0,val2=0;

int main()
{
    scanf("%d%d",&n,&bx);
    rep1(i,1,n)
    {
        int a; scanf("%d",&a);
        val1=val1*bx+a;
    }
    scanf("%d%d",&m,&by);
    rep1(i,1,m)
    {
        int a; scanf("%d",&a);
        val2=val2*by+a;
    }
    if (val1<val2) puts("<");
        else if (val1==val2) puts("=");
            else puts(">");
    return 0;
}