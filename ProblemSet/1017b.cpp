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

const int maxn=1e5+10;
int n,f[maxn][4];
char a[maxn],b[maxn];
ll ans=0;

int cal(int x)
{
    return 2*(a[x]-'0')+b[x]-'0';
}

int main()
{
    scanf("%d",&n);
    scanf("%s%s",a+1,b+1);
    for (int i=n;i>=1;i--)
    {
        rep0(j,0,4)
            f[i][j]=f[i+1][j];
        f[i][cal(i)]++;
    }
    rep0(i,1,n)
        switch (cal(i))
        {
            case 0: ans+=f[i+1][2]+f[i+1][3]; break;
            case 1: ans+=f[i+1][2]; break;
            case 2: ans+=f[i+1][0]+f[i+1][1]; break;
            case 3: ans+=f[i+1][0]; break;
            default: break;
        }
    printf("%lld\n",ans);
    return 0;
}