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

const int maxn=1e3+10;
char s[maxn],t[maxn];
int n,m,ansSize=inf;
vector<int>ans,tmp;

int main()
{
    ans.clear(); tmp.clear();
    scanf("%d%d",&n,&m);
    scanf("%s",s);
    scanf("%s",t);
    rep1(i,0,m-n)
    {
        rep0(j,0,n)
            if (s[j]!=t[i+j]) tmp.pb(j+1);
        if ((int)tmp.size()<ansSize)
        {
            ansSize=tmp.size();
            ans=tmp;
        }
        tmp.clear();
    }
    printf("%d\n",ansSize);
    repa(i,ans) printf("%d ",i);
    puts("");
    return 0;
}