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

const int maxn=2e3+10;
int n,k,ans=0;
pair<int,int> a[maxn];
vector<int>b;

int main()
{
    b.clear();
    scanf("%d%d",&n,&k);
    rep0(i,0,n)
    {
        scanf("%d",&a[i].fir); a[i].sec=i;
    }
    sort(a,a+n);
    b.pb(-1);
    for (int i=n-1;i>=n-k;i--)
    {
        ans+=a[i].fir;
        b.pb(a[i].sec);
    }
    printf("%d\n",ans);
    sort(b.begin(),b.end());
    b[b.size()-1]=n-1;
    rep0(i,1,b.size()) printf("%d ",b[i]-b[i-1]);
    puts("");
    return 0;
}