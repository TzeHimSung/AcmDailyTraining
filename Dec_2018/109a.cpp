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

int n,sign=0,i,j,t;

int main()
{
    scanf("%d",&n);
    for (i=0;i*4<=n;i++)
        for (j=n/7;j>=0;j--)
        {
            t=4*i+7*j;
            if (t==n)
            {
                sign=1;
                goto mark;
            }
        }
    mark:
    if (sign)
    {
        while (i--) printf("4");
        while (j--) printf("7");
        puts("");
    }
    else puts("-1");
    return 0;
}