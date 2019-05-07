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
int n,a[maxn];

int main()
{
    init(a,0); scanf("%d",&n);
    rep0(i,2,maxn)
        if (!a[i])
            for (int j=2*i;j<maxn;j+=i) a[j]=1;
    if (n>2) puts("2"); else puts("1");
    rep1(i,2,n+1)
        if (a[i]) printf("2 "); else printf("1 ");
    puts("");
    return 0;
}