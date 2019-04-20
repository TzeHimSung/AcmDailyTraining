//basic
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <climits>
#include <algorithm>
#include <cmath>
#include <array>
#include <cstdint>
#include <iterator>
//STL
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
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
//namespace
using namespace std;
//header end

const int maxn=1e2+10;
int n,m,a[maxn];

int main()
{
    init(a,0);
    scanf("%d",&n);
    rep1(i,1,n) scanf("%d",&a[i]);
    scanf("%d",&m);
    rep1(i,1,m)
    {
        int x,y; scanf("%d%d",&x,&y);
        if (x>1) a[x-1]+=y-1;
        if (x<n) a[x+1]+=a[x]-y;
        a[x]=0;
    }
    rep1(i,1,n) printf("%d\n",a[i]);
    return 0;
}