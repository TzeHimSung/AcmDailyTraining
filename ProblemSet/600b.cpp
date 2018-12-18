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
#define pb push_back
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

int n,m;
const int maxn=2e5+10;
int a[maxn],b[maxn],maxx=0;

int main()
{
    init(a,0); init(b,0);
    scanf("%d%d",&n,&m);
    rep1(i,1,n) scanf("%d",&a[i]);
    sot(a,n);
    rep1(i,1,m)
    {
        int x; scanf("%d",&x);
        printf("%d ",upper_bound(a+1,a+1+n,x)-a-1);
    }
    return 0;
}