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

int n,k,ans=0;
priority_queue<int>q;

int main()
{
    while (!q.empty()) q.pop();
    scanf("%d%d",&n,&k);
    rep0(i,1,n)
    {
        int x; scanf("%d",&x); q.push(x);
    }
    while (k<=q.top())
    {
        k++; ans++;
        int x=q.top();
        q.pop(); q.push(x-1);
    }
    printf("%d\n",ans);
    return 0;
}