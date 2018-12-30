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

const int maxn=5e5+10;
int a[maxn],n;
vector<int>ans;

bool check()
{
    for (int i=0;i<n-1;i++)
    {
        sort(a+i,a+n,greater<int>());
        if (i+a[i]>=n) return false;
        rep1(j,i+1,i+a[i])
        {
            a[j]--;
            if (a[j]<0) return false;
        }
    }
    if (a[n-1]!=0) return false;
    return true;
}

int main()
{
    scanf("%d",&n);
    ans.clear();
    rep1(i,0,n-1) scanf("%d",&n);
    n++;
    rep1(i,0,n)
    {
        a[n]=i;
        if (check()) ans.pb(i);
    }
    repa(i,ans) printf("%d ",i);
    puts("");
    return 0;
}