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

int a,b,c,d,x=0,y=0;

int exgcd(int a, int b, int &x, int &y)
{
    if (!b) {x=1; y=0; return a;}
    else
    {
        int r=exgcd(b,a%b,y,x);
        y-=x*(a/b);
        return r;
    }
}

int main()
{
    scanf("%d%d%d%d",&a,&b,&c,&d);
    int g=exgcd(a,-c,x,y);
    if ((d-b)%g!=0)
    {
        puts("-1");
        return 0;
    }
    x=x*(d-b)/g; x=x%(-c/g);
    if (x<0) x+=abs(-c/g);
    y=-(d-b-a*x)/c;
    while (y<0)
    {
        x+=abs(-c/g);
        y=-(d-b-a*x)/c;
    }
    printf("%d\n",x*a+b);
    return 0;
}