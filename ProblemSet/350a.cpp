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

const int maxn=1e2+10;
int n,m,a[maxn],b[maxn];
int amax=0,amin=inf,bmin=inf;

int main()
{
    init(a,0); init(b,0); scanf("%d%d",&n,&m);
    rep1(i,1,n) 
    {
        scanf("%d",&a[i]);
        amax=max(amax,a[i]);
        amin=min(amin,a[i]);
    }
    rep1(i,1,m) 
    {
        scanf("%d",&b[i]);
        bmin=min(bmin,b[i]);
    }
    if (amax>=bmin)
    {
        puts("-1");
        return 0;
    }
    else
    {
        if (2*amin>=bmin)
        {
            puts("-1");
            return 0;
        }
        else
        {
            amax=max(amax,amin*2);
            printf("%d\n",amax);
        }
    }
    return 0;
}