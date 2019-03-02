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

int n,h,a,b,k;

int main()
{
    scanf("%d%d%d%d%d",&n,&h,&a,&b,&k);
    while (k--)
    {
        int p1,q1,p2,q2; scanf("%d%d%d%d",&p1,&q1,&p2,&q2);
        int ans=abs(p1-p2);
        if (!ans)
        {
            ans=abs(q1-q2);
            goto mark;
        }
        if (q1>b && q2>b) ans+=q1-b+q2-b;
        else if (q1<a && q2<a) ans+=a-q1+a-q2;
        else ans+=abs(q1-q2);
        mark:;
        printf("%d\n",ans);
    }
    return 0;
}