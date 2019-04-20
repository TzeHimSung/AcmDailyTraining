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
#define lson curr<<1
#define rson curr<<1|1
//namespace
using namespace std;
//header end

int h,m,x,ans=0;

int main()
{
    scanf("%d%d%d",&x,&h,&m);
    if (h==7 || h%10==7 || m==7 || m%10==7)
    {
        puts("0");
        return 0;
    }
    else
    {
        while (1)
        {
            if (m-x<0)
            {
                m+=60-x;
                h--;
                if (h<0) h=23;
            }
            else m-=x;
            ans++;
            if (h==7 || h%10==7 || m==7 || m%10==7) break;
        }
    }
    printf("%d\n",ans);
    return 0;
}