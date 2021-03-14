#include <bits/stdc++.h>
#define pii pair<int,int>
#define ll long long 
#define pb push_back

using namespace std;

const int maxn=4e3+10;
int n,k,total=0;
ll sum=0;

vector<int>W[maxn];

bool cmp(pii a, pii b)
{
    return a.first>b.first;
}

void solve()
{
    vector<pii>p; vector<ll>sums;
    for (int i=1;i<=4000;i++)
    {
        sort(W[i].begin(),W[i].end());
        reverse(W[i].begin(),W[i].end());
        if (!W[i].empty())
            p.pb(pii(W[i].size(),i));
    }
    if (p.size()<k) return;
    sort(p.begin(),p.end(),cmp);
    int lowerBoundSize=p[k-1].first;
    for (int i=0;i<p.size();i++)
    {
        if (p[i].first<lowerBoundSize) break;
        int mass=p[i].second;
        ll add=0;
        for (int k=0;k<lowerBoundSize;k++)
            add+=W[mass][k];
        sums.pb(add);
    }
    sort(sums.begin(),sums.end());
    reverse(sums.begin(),sums.end());
    total=lowerBoundSize;
    for (int i=0;i<k;i++) sum+=sums[i];
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    scanf("%d%d",&n,&k);
    for (int i=1;i<=n;i++)
    {
        int w,cost;
        scanf("%d%d",&w,&cost);
        W[w].pb(cost);
    }
    solve();
    printf("%d %lld\n",total,sum);

    fclose(stdin);
    fclose(stdout);
    return 0;
}