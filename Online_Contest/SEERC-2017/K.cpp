#include <bits/stdc++.h>
#define ll long long 
#define pb push_back 

using namespace std;

const int maxn=1e5+10;
struct Node
{
    int len,val,pos;
};

Node a[maxn];
int n;

bool cmp(const Node &a, const Node &b)
{
    if (a.len==b.len)
        return a.pos<b.pos;
    else
        return a.len<b.len;
}

bool cmp2(const Node &a, const Node &b)
{
    return a.pos<b.pos;
}

int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&a[i].len);
        a[i].pos=i;
    }
    sort(a+1,a+1+n,cmp);
    for (int i=1;i<=n;i++) a[i].val=n-i+1;
    sort(a+1,a+1+n,cmp2);
    for (int i=1;i<n;i++) printf("%d ",a[i].val);
    printf("%d\n",a[n].val);
    return 0;
}