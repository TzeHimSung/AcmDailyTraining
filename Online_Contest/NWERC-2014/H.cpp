#include <bits/stdc++.h>
#define ll long long 
#define pb push_back

using namespace std;

const int maxn = 1e4+10;

vector<int> edges[maxn];
int freq[maxn][2], idx;

void DFS(int u, int p, int f) 
{
    freq[u][0] = f;
    freq[u][1] = idx++; 
    int cnt = 0;
    for(int i=0; i<edges[u].size(); ++i) 
    {
        int v = edges[u][i];
        if(v != p) 
        {
            if(cnt == 0) DFS(v, u, freq[u][1]); 
            else DFS(v, u, freq[u][0]);
            cnt++;
        }
    }
}

int main() 
{
    int n, u, v;
    while(~ scanf("%d", &n)) 
    {
        for(int i=1; i<=n; ++i) edges[i].clear();
        for(int i=0; i<n-1; ++i) 
        {
            scanf("%d %d", &u, &v);
            edges[u].push_back(v);
            edges[v].push_back(u);
        }
        if(n == 2) printf("0 1\n1 0\n");
        else 
        {
            idx = 1;
            DFS(1, -1, 0);
            for(int i=1; i<=n; ++i)
                printf("%d %d\n", freq[i][0], freq[i][1]);
        }
    }
    return 0;
}