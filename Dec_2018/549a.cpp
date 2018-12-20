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
const int maxn=60;
char s[maxn][maxn];
const int px[]{0,0,1,1};
const int py[]{0,1,0,1};

int main()
{
    scanf("%d%d",&n,&m);
    rep1(i,1,n) scanf("%s",s[i]+1);
    int ans=0;
    rep1(i,1,n-1)
        rep1(j,1,m-1)
        {
            int s1=0,s2=0,s3=0,s4=0;
            rep0(k,0,4)
            {
                int nx=i+px[k],ny=j+py[k];
                if (nx<=n && ny<=m && s[nx][ny]=='f') s1=1;
                if (nx<=n && ny<=m && s[nx][ny]=='a') s2=1;
                if (nx<=n && ny<=m && s[nx][ny]=='c') s3=1;
                if (nx<=n && ny<=m && s[nx][ny]=='e') s4=1;
            }
            if (s1+s2+s3+s4==4) ans++;
        }
    printf("%d\n",ans);
    return 0;
}