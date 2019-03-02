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
#define mem(a,b) memset(a,b,sizeof(a))
#define init(a,b) fill(begin(a),end(a),b)
#define eps 1e-8
#define pi 3.1415926 
//namespace
using namespace std;
//header end

int n,k;
struct Node
{
    int pre,cur;
    bool operator<(const Node &rhs)const
    {
        return (pre-cur)<(rhs.pre-rhs.cur);
    }
};
const int maxn=2e5+10;
Node a[maxn];

int main()
{
    scanf("%d%d",&n,&k);
    for (int i=1;i<=n;i++) scanf("%d",&a[i].pre);
    int ans=0,num=0;   
    for (int i=1;i<=n;i++) 
    {
        scanf("%d",&a[i].cur);
        ans+=a[i].cur;
        if (a[i].pre-a[i].cur<=0) num++;
    }
    sort(a+1,a+1+n);
    if (num>=k)
    {
        for (int i=1;i<=n;i++)
        {
            if (a[i].pre-a[i].cur<0) ans+=a[i].pre-a[i].cur;
            else break;
        }
        printf("%d\n",ans);
    }
    else
    {
        for (int i=1;i<=k;i++) ans+=a[i].pre-a[i].cur;
        printf("%d\n",ans);
    }
    return 0;
}