//basic
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <climits>
#include <cmath>
#include <cstdint>
//STL
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <array>
#include <iterator>
//define
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
//namespace
using namespace std;
//header end

const int maxn=1e2+10;
int n,a[maxn];

int main()
{
    init(a,0);
    scanf("%d",&n);
    rep1(i,1,n) scanf("%d",&a[i]);
    int x=1,y=n,maxx=abs(a[1]-a[n]);
    rep0(i,1,n)
    {
        if (abs(a[i]-a[i+1])<maxx)
            maxx=abs(a[i]-a[i+1]),x=i,y=i+1;
    }
    printf("%d %d\n",x,y);
    return 0;
}