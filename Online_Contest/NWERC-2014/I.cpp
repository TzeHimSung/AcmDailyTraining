#include <bits/stdc++.h>
#define ll long long 
#define pb push_back

using namespace std;

int n,t[15];
ll l,g[15][15];
vector<ll>b[1<<14][14];

void dfs1(int now,int dep,int mask,ll w)
{
    if (!dep)
    {
        b[mask][now].pb(w);
        return;
    }
    for (int i=1;i<n;i++)
        if (mask & (1<<i))
        dfs1(i,dep-1,mask^(1<<i),w+g[now][i]);
}

void dfs2(int now,int dep,int mask,ll w)
{
    if (!dep)
    {
        
    }
}