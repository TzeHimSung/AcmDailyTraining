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

ll n,k,x,remain=1e18+10,buy=0;
int num=1;
const int maxn=1e5+10;

int main()
{
    scanf("%lld%lld",&n,&k);
    rep1(i,1,k)
    {
        scanf("%lld",&x);
        if (x>n) continue;
        ll tmp=n%x;
        if (tmp<remain)
        {
            num=i;
            remain=tmp;
            buy=n/x;
        }
    }   
    printf("%d %lld\n",num,buy);
    return 0;
}