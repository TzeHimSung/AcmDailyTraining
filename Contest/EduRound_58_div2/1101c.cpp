/* basic header */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <climits>
#include <cmath>
#include <cstdint>
/* STL */
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <array>
#include <iterator>
/* define */
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
/* namespace */
using namespace std;
/* header end */

int t,n;
struct Node
{
    int l,r,k;
};
const int maxn=1e5+10;
Node a[maxn];
int ans[maxn];

bool cmp(Node &a, Node &b)
{
    if (a.l==b.l)
        return a.r>b.r;
    return a.l<b.l;
}

int main()
{
    scanf("%d",&t);
    while (t--)
    {
        scanf("%d",&n);
        rep1(i,1,n)
        {
            scanf("%d%d",&a[i].l,&a[i].r);
            a[i].k=i;
        }
        sort(a+1,a+1+n,cmp);
        int r=1,flag=0;
        rep0(l,1,n)
        {
            while(r<n && a[r+1].l<=a[l].r) r++;
            if (l==r) //broken
            {
                rep1(i,1,l) ans[a[i].k]=1;
                rep1(i,l+1,n) ans[a[i].k]=2;
                flag=1;
                break;
            }
        }
        if (!flag) puts("-1");
        else
        {
            rep1(i,1,n) printf("%d ",ans[i]);
            puts("");
        }
    }
    return 0;
}