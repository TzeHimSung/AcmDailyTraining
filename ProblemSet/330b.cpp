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

const int maxn=1e4+10;
int n,m,a[maxn];

int main()
{
    init(a,0);
    scanf("%d%d",&n,&m);
    rep1(i,1,m)
    {
        int x,y; scanf("%d%d",&x,&y);
        a[x]++,a[y]++;
    }
    int pub=0;
    rep1(i,1,n)
        if (!a[i]) {pub=i; break;}
    printf("%d\n",n-1);
    rep1(i,1,n)
        if (i!=pub) printf("%d %d\n",i,pub);
    return 0;
}