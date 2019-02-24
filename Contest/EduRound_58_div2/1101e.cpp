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

int n;
const int maxn=30;
char s[maxn];

int main()
{
    scanf("%d",&n);
    cin.get();
    int maxx=INT_MIN,maxy=INT_MIN;
    while (n--)
    {
        char c; int x,y;
        scanf("%c %d %d",&c,&x,&y);
        cin.get();
        if (x>y) swap(x,y);
        if (c=='+')
        {
            maxx=max(x,maxx); maxy=max(y,maxy);
            if (maxx>maxy) swap(maxx,maxy);
        }
        else
        {
            if (x>=maxx && y>=maxy) puts("YES");
                else puts("NO");
        }
    }
    return 0;
}