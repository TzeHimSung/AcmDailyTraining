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
//namespace
using namespace std;
//header end

const int maxn=2e5+10;
int n,a[maxn],f[maxn],ans=1;

int main()
{
    scanf("%d",&n); init(a,0); init(f,0); f[1]=1;
    rep1(i,1,n) scanf("%d",&a[i]);
    rep1(i,2,n)
    {
        if (a[i]<=2*a[i-1]) f[i]=f[i-1]+1;
        else f[i]=1;
        ans=max(ans,f[i]);
    }
    printf("%d\n",ans);
    return 0;
}