#include <bits/stdc++.h>

using namespace std;

const int maxn=1e4+10;
struct Node
{
    int a,s;
    bool operator<(const Node &rhs)const
    {
        return a>rhs.a;
    }
};

Node ba[maxn];
int n;
double ans1=0,ans2=0;

double solve()
{
    double re=0,v=0,t;
    for (int i=1;i<=n;i++)
    {
        t=ba[i].s;
        re+=v*t+ba[i].a*t*t/2.0;
        v+=ba[i].a*t;
    }
    return re;
}

int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d%d",&ba[i].a,&ba[i].s);
    ans1=solve();
    sort(ba+1,ba+1+n);
    ans2=solve();
    printf("%.1f\n",ans2-ans1);
    return 0;
}