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

const int maxn=20;
int a[maxn],n,l,r,x,ans=0,k;

int dfs(int curr,int sum)
{
    sum+=a[curr];
    if (sum>r) return 0;
    if (sum>=l && sum<=r && a[curr]-a[k]>=x) ans++;
    rep1(j,curr+1,n) dfs(j,sum);
}

int main()
{
    init(a,0);
    scanf("%d%d%d%d",&n,&l,&r,&x);
    rep1(i,1,n) scanf("%d",&a[i]);
    sot(a,n);
    for (k=1;k<n;k++)
        if (a[k]+a[k+1]>r) break; else dfs(k,0);
    printf("%d\n",ans);
    return 0;
}