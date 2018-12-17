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

const int maxn=1e3+10;
int n,a[maxn],ans=0;

bool isP(int x)
{
    rep1(i,2,x-1)
        if (x%i==0) return 0;
    return 1;
}

int main()
{
    scanf("%d",&n);
    init(a,0);
    rep1(i,2,n)
    {
        if (!isP(i)) continue;
        int p=i;
        while (p<=n)
        {
            a[++ans]=p;
            p*=i;
        }
    }
    printf("%d\n",ans);
    rep1(i,1,ans) printf("%d ",a[i]); 
    return 0;
}