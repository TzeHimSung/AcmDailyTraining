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

const int maxn=1e3+10;
int n,m,k,ans=0;

int main()
{
    scanf("%d%d%d",&n,&m,&k);
    rep1(i,1,n)
    {
        int x; scanf("%d",&x);
        if (x==1) m--;
        else
        {
            if (k>0) k--;
            else if (m>0) m--;
            else k--;
        }
        if (m<0) m=0,ans++;
        if (k<0) k=0,ans++;
    }
    printf("%d\n",ans);
    return 0;
}