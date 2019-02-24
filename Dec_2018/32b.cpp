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

const int maxn=2e2+10;
char s[maxn];
int len,a[maxn];

int main()
{
    init(a,0);
    scanf("%s",s+1);
    len=strlen(s+1);
    rep1(i,1,len)
    {
        if (s[i]=='-')
        {
            i++;
            if (s[i]=='.') a[++a[0]]=1;
            else a[++a[0]]=2;
        }
        else a[++a[0]]=0;
    }
    rep1(i,1,a[0]) printf("%d",a[i]);
    puts("");
    return 0;
}