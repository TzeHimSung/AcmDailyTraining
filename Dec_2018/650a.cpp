//basic
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <climits>
#include <algorithm>
#include <cmath>
//STL
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>

#define ll long long 
#define pb push_back
#define mp make_pair 

using namespace std;

const int maxn=2e5+10;
struct Node
{
    int x,y;
};

Node a[maxn];
int n;
ll ans=0;

int cmpx(Node &a, Node &b)
{
    if (a.x!=b.x) return a.x<b.x;
    else return a.y<b.y;
}

int cmpy(Node &a, Node &b)
{
    if (a.y!=b.y) return a.y<b.y;
    else return a.x<b.x;
}

ll calc(int n)
{
    if (n<2) return 0;
    else
    {
        ll x=1;
        for (int i=1;i<=2;i++) x=x*(n-i+1)/i;
        return x;
    }
}

int main()
{
    scanf("%d",&n);
    for (int i=0;i<n;i++) scanf("%d%d",&a[i].x,&a[i].y);
    sort(a,a+n,cmpx);
    int t=0,cnt=1;
    for (int i=1;i<n;i++)
    {
        if (a[i].x==a[t].x) cnt++;
        else
        {
            ans+=calc(cnt);
            cnt=1;
            t=i;
        }
    }
    ans+=calc(cnt);
    sort(a,a+n,cmpy);
    int num=1; t=0,cnt=1;
    for (int i=1;i<n;i++)
    {
        if (a[i-1].x==a[i].x && a[i-1].y==a[i].y) num++;
        else
        {
            ans-=calc(num);
            num=1;
        }
        if (a[i].y==a[t].y) cnt++;
        else
        {
            ans+=calc(cnt);
            cnt=1;
            t=i;
        }
    }
    ans+=calc(cnt);
    ans-=calc(num);
    printf("%lld\n",ans);
    return 0;
}