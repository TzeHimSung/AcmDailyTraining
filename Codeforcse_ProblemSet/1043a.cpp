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
int n,a[maxn],sum=0,maxx=0;

int main()
{
    init(a,0);
    scanf("%d",&n);
    rep1(i,1,n) 
    {
        scanf("%d",&a[i]);
        sum+=a[i];
        maxx=max(maxx,a[i]);
    }
    rep1(i,maxx,inf)
    {
        int tmp=0;
        rep1(j,1,n) tmp+=i-a[j];
        if (tmp>sum)
        {
            printf("%d\n",i);
            return 0;
        }
    }
    return 0;
}