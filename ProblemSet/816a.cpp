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
//namespace
using namespace std;
//header end

string s;
int h,m;

int main()
{
    cin>>s; int ans=0;
    h=(s[0]-'0')*10+s[1]-'0';
    m=(s[3]-'0')*10+s[4]-'0';
    int a=h/10,b=h%10,c=m/10,d=m%10;
    if (a==d && b==c) {puts("0"); return 0;}
    while (1)
    {
        ans++,m++;
        if (m==60) h++,m=0;
        if (h==24) h=0,m=0;
        int a=h/10,b=h%10,c=m/10,d=m%10;
        if (a==d && b==c) break;
    }
    printf("%d\n",ans);
    return 0;
}