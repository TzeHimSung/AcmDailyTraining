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
#define ll long long 
#define pb push_back
#define mp make_pair 
#define init(a,b) fill(begin(a),end(a),b)
#define sot(a,b) sort(a+1,a+1+b)
#define rep(i,a) for(int i=1;i<=a;i++)
#define eps 1e-8
#define int int32_t
#define ll int64_t
//namespace
using namespace std;
//header end

const int maxn=2e5+10;
int n;
ll sum=0;
vector<int>ans;
struct Node
{
    int num,pos;
    bool operator<(const Node &rhs)const
    {
        return num<rhs.num;
    }
}a[maxn];

int main()
{
    ans.clear();
    scanf("%d",&n);
    rep(i,n)
    {
        scanf("%d",&a[i].num);
        a[i].pos=i; sum+=a[i].num;
    }
    sot(a,n);
    rep(i,n)
    {
        if (i<n && sum-a[i].num-a[n].num==a[n].num)
            ans.pb(a[i].pos);
        else if (i==n && sum-a[i].num-a[n-1].num==a[n-1].num)
            ans.pb(a[i].pos);
    }
    if (!ans.size()) puts("0");
    else
    {
        printf("%d\n",ans.size());
        for (auto i:ans) printf("%d ",i);
        puts("");
    }
    return 0;
}