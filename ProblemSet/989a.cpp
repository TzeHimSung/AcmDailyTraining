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
char s[maxn];

int main()
{
    scanf("%s",s+1);
    int len=strlen(s+1);
    rep1(i,1,len-2)
    {
        int a=0,b=0,c=0;
        if (s[i]=='A') a=1; else if (s[i]=='B') b=1; else if (s[i]=='C') c=1;
        if (s[i+1]=='A') a=1; else if (s[i+1]=='B') b=1; else if (s[i+1]=='C') c=1;
        if (s[i+2]=='A') a=1; else if (s[i+2]=='B') b=1; else if (s[i+2]=='C') c=1;
        if (a+b+c==3)
        {
            puts("Yes");
            return 0;
        }
    }
    puts("No");
    return 0;
}