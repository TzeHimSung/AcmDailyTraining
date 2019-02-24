/* basic header */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <climits>
#include <cmath>
#include <cstdint>
/* STL */
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <array>
#include <iterator>
/* define */
#define int int32_t
#define ll int64_t
#define dou double
#define pb emplace_back
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
#define lson curr<<1
#define rson curr<<1|1
/* namespace */
using namespace std;
/* header end */

char a,b;
int n;

char clockRotate(char x)
{
    if (x=='^') return '>';
    else if (x=='>') return 'v';
    else if (x=='v') return '<';
    else return '^';
}

char disClockRotate(char x)
{
    if (x=='^') return '<';
    else if (x=='<') return 'v';
    else if (x=='v') return '>';
    else return '^';
}

int main()
{
    scanf("%c %c",&a,&b);
    scanf("%d",&n);
    char c=a,d=a; int time1=0,time2=0,sign1=0,sign2=0;
    while (c!=b)
    {
        c=clockRotate(c);
        time1++;
    }
    if ((n-time1)%4==0) sign1=1;
    while (d!=b)
    {
        d=disClockRotate(d);
        time2++;
    }
    if ((n-time2)%4==0) sign2=1;
    if (sign1 && !sign2) puts("cw");
        else if (sign2 && !sign1) puts("ccw");
            else puts("undefined");
    return 0;
}