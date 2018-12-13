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

set<int>a;
int n,m,mina=INT_MAX,minb=INT_MAX,x,ans=INT_MAX;

int main()
{
    a.clear(); 
    scanf("%d%d",&n,&m);
    while (n--)
    {
        scanf("%d",&x); a.insert(x);
        mina=min(mina,x);
    }
    while (m--)
    {
        scanf("%d",&x); 
        minb=min(minb,x);
        if (a.count(x)) ans=min(ans,x);
    }
    if (mina>minb && minb!=0) swap(mina,minb);
    if (mina!=minb) printf("%d\n",min(ans,mina*10+minb)); else printf("%d\n",min(ans,mina));
    return 0;
}