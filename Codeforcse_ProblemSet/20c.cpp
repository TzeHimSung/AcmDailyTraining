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
//define
#define ll long long 
#define pb push_back
#define mp make_pair 
#define mem(a,b) memset(a,b,sizeof(a))
#define eps 1e-8

using namespace std;

const int maxn=1e5+10;
const int maxm=1e5+10;
const ll inf=0x3f3f3f3f3f3f3f3f;
ll dis[maxn];
bool vis[maxn];
int path[maxn],n,m;

struct Node
{
    int to,w;
    Node(){}
    Node(int a, int b):to(a),w(b){}
};
vector<Node>e[maxn];

void spfa(int st, int n)
{
    mem(dis,inf);
    mem(vis,false);
    queue<int>q; while (!q.empty()) q.pop();
    dis[st]=0;
    q.push(st);
    while (!q.empty())
    {
        int curr=q.front();
        q.pop();
        vis[curr]=false;
        if (dis[curr]>dis[n]) continue;
        int size=e[curr].size();
        for (int i=0;i<size;i++)
        {
            int to=e[curr][i].to,w=e[curr][i].w;
            if (dis[to]>dis[curr]+w)
            {
                dis[to]=dis[curr]+w;
                path[to]=curr;
                if (!vis[to])
                {
                    vis[to]=true;
                    q.push(to);
                }
            }
        }
    }
}

int main()
{
    int a[maxn]; mem(a,-1);
    scanf("%d%d",&n,&m);
    for (int i=0;i<m;i++)
    {
        int x,y,z; scanf("%d%d%d",&x,&y,&z);
        e[x].pb(Node(y,z));
        e[y].pb(Node(x,z));
    }
    spfa(1,n);
    if (dis[n]==inf)
        puts("-1");
    else
    {
        int k=0; a[k++]=n;
        for (int i=n;i>1;)
        {
            int j=path[i];
            a[k]=j;
            i=j;
            k++;
        }
        for (int i=k-1;i>=0;i--)
        {
            printf("%d",a[i]);
            if (i>=1) printf(" ");
            else puts("");
        }
    }
    return 0;
}