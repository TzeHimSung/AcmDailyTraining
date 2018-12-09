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

const int maxn=2e5+10;
int n,a[maxn],pos1,pos2;
ll sum=0,sum1=0,sum2=0;

int main()
{
    scanf("%d",&n); 
    rep1(i,1,n)
    {
        scanf("%d",&a[i]); sum+=a[i];
    }
    rep1(i,1,n)
    {
        sum1+=a[i];
        if (sum1>=(sum+1)/2)
        {
            pos1=i,pos2=i+1;
            break;
        }
    }
    sum2=sum-sum1;
    if (sum1==sum2)
    {
        printf("%lld\n",sum1);
        return 0;
    }
    while (sum1-sum2)
    {
        if (sum1>sum2) sum1-=a[pos1--];
        if (sum2>sum1) sum2-=a[pos2++];
    }
    printf("%lld\n",sum1);
    return 0;
}