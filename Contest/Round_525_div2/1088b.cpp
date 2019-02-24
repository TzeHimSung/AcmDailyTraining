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
//namespace
using namespace std;
//header end

const int maxn=1e5+10;
int n,k,a[maxn],b[maxn],p=0;

int main()
{
    init(a,0); a[0]=-1;
    scanf("%d%d",&n,&k);
    rep1(i,1,n) scanf("%d",&a[i]);
    sot(a,n); 
    rep1(i,1,n)
        if (a[i]!=a[i-1]) b[++p]=a[i];
    int delta=0;
    rep1(i,1,p)
        if (b[i]-delta>0)
        {
            printf("%d\n",b[i]-delta);
            delta+=b[i]-delta;
            if (!--k) return 0;
        }
    rep1(i,1,k) puts("0");
    return 0;   
}