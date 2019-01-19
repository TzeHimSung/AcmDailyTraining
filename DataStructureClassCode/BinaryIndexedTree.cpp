#include <bits/stdc++.h>

using namespace std;

const int maxn=1e4+10;
int n,a[maxn],c[maxn];

int lowbit(int x) { return x & (-x); }

int sum(int pos)
{
    int ret=0;
    while (pos>0)
    {
        ret+=c[pos];
        pos-=lowbit(pos);
    }
    return ret;
}

void reNew(int pos, int val)
{
    while (pos<=n)
    {
        c[pos]+=val;
        pos+=lowbit(pos);
    }
}

int main()
{
    memset(a,0,sizeof(a));
    memset(c,0,sizeof(c));
    cin>>n; 
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        reNew(i,a[i]);
    }
    for (int i=n;i>=1;i--)
        cout<<sum(i)<<endl;
    return 0;
}