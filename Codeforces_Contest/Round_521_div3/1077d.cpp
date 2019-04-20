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
#define ll long long 
#define pb push_back
#define mp make_pair 
#define init(a,b) fill(begin(a),end(a),b)
#define sot(a,b) sort(a+1,a+1+b)
#define rep(i,a) for(int i=1;i<=a;i++)
#define eps 1e-8
#define int int32_t
#define ll int64_t
//namespace
using namespace std;
//header end

const int maxn=2e5+1;
int a[maxn];
int n,k,x;

bool judge(int ch)
{
    int re=0;
    rep(i,2e5)
    {
        if (a[i]<ch) continue; 
            else re+=a[i]/ch;
    }
    return re>=k;
}

int main()
{
    init(a,0);
    scanf("%d%d",&n,&k);
    vector<int>ans(k); ans.clear();
    rep(i,n)
    {
        scanf("%d",&x);
        a[x]++;
    }
    int l=1,r=n,mid,times=1;
    while (l<=r)
    {
        mid=(l+r)/2;
        if (judge(mid)) 
            times=mid,l=mid+1;
        else
            r=mid-1; 
    }
    int cnt=0;
    rep(i,2e5)
    {
        if (a[i]<times) continue;
        rep(j,a[i]/times)
        {
            ans.pb(i); cnt++;
            if (cnt==k) goto mark;
        }
    }
    mark:;
    for (auto i:ans) cout<<i<<" ";
    puts("");
    return 0;
}