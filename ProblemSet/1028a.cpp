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

int n,m;
const int maxn=120;
char s[maxn][maxn];
int top=-1,btn=-1,le=-1,ri=-1;

int main()
{
    scanf("%d%d",&n,&m);
    rep1(i,1,n) scanf("%s",s[i]+1);
    rep1(i,1,n)
        rep1(j,1,m)
            if (s[i][j]=='B')
            {
                btn=i,ri=j;
                if (top==-1) top=i;
                if (le==-1) le=j;
            }
    printf("%d %d\n",(top+btn)/2,(le+ri)/2);
    return 0;
}