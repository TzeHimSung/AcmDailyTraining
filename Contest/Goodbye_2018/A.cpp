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

int y,b,r;

int main()
{  
    scanf("%d%d%d",&y,&b,&r);
    int maxx=0;
    if (y+1<=b && b+1<=r) maxx=y+y+1+y+2;
    if (b-1<=y && b+1<=r) maxx=max(maxx,b+b-1+b+1);
    if (r-2<=y && r-1<=b) maxx=max(maxx,r-2+r+r-1);
    printf("%d\n",maxx);
    return 0;
}