#include<bits/stdc++.h>

using namespace std;

const int inf=1<<29;
const int maxn=200;
const int maxm=maxn*maxn*3;
int n,e,st,s_st,s_des,des,head[maxn],nxt[maxm],pnt[maxm],flow[maxm],level[maxn];
int c_in[maxn],c_out[maxn],out[maxn];
bool go[maxn][maxn];
queue<int> q;

void AddEdge(int u,int v,int f)
{
    pnt[e]=v;nxt[e]=head[u];flow[e]=f;head[u]=e++;
    pnt[e]=u;nxt[e]=head[v];flow[e]=0;head[v]=e++;
}

bool BFS()
{
    memset(level,0,sizeof(level));
    level[st]=1;
    q.push(st);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=head[u];i!=-1;i=nxt[i])
            if(flow[i]&&!level[pnt[i]])
            {
                level[pnt[i]]=level[u]+1;
                q.push(pnt[i]);
            }
    }
    return level[des];
}

int DFS(int u,int maxf)
{
    if(u==des||!maxf)
        return maxf;
    for(int i=head[u],t;i!=-1;i=nxt[i])
        if(level[pnt[i]]==level[u]+1&&(t=DFS(pnt[i],min(maxf,flow[i]))))
        {
            flow[i]-=t;
            flow[i^1]+=t;
            return t;
        }
    return level[u]=0;
}

int maxflow(int s,int t)
{
    st=s;des=t;
    int ans=0;
    while(BFS())
        while(1)
        {
            int val=DFS(st,inf);
            if(!val)
                break;
            ans+=val;
        }
    return ans;
}

bool check(int val)
{
    e=st=0,des=n+1,s_st=n+2,s_des=n+3;
    memset(head,-1,sizeof(head));
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(go[i][j])
                AddEdge(i,j,inf);
    for(int i=1;i<=n;i++)
    {
        AddEdge(st,i,inf);
        AddEdge(i,des,inf);
    }
    AddEdge(des,st,val);
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        if(c_in[i]>c_out[i])
        {
            AddEdge(s_st,i,c_in[i]-c_out[i]);
            sum+=c_in[i]-c_out[i];
        }
        if(c_in[i]<c_out[i])
            AddEdge(i,s_des,c_out[i]-c_in[i]);
    }
    int f=maxflow(s_st,s_des);
    return f==sum;
}

int cap[maxn][maxn];

int dfs(int u,int cnt)
{
    out[cnt]=u;
    if(u==des)
    {
        for(int i=1;i<cnt;i++)
            printf("%d%c",out[i],i==cnt-1?'\n':' ');
        return 1;
    }
    for(int i=1;i<=des;i++)
        if(cap[u][i])
        {
            cap[u][i]--;
            if(dfs(i,cnt+1))
                return 1;
        }
    return 0;
}
void solve()
{
    int sl=0,sr=inf,ans=0;
    while(sl<=sr)
    {
        int mid=(sl+sr)>>1;
        if(check(mid))
        {
            sr=mid-1;        
            ans=mid;
        }
        else
            sl=mid+1;
    }
    printf("%d\n",ans);
    check(ans);
    st=0;des=n+1;
    for(int i=1;i<=n;i++)
        cap[st][i]=cap[i][des]=1;
    for(int u=0;u<=n;u++)
        for(int i=head[u];i!=-1;i=nxt[i])
            if(cap[u][pnt[i]])
                cap[u][pnt[i]]=flow[i^1]+1-(u==st||pnt[i]==des);
    for(int i=1;i<=des;i++)
        while(cap[st][i])
        {
            cap[st][i]--;
            dfs(i,1);
        }
}
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        memset(c_in,0,sizeof(c_in));
        memset(c_out,0,sizeof(c_out));
        memset(go,0,sizeof(go));
        for(int i=1;i<=n;i++)
        {
            int m;
            scanf("%d",&m);
            for(int j=0;j<m;j++)
            {
                int v;
                scanf("%d",&v);
                go[i][v]=1;
                cap[i][v]=1;
                c_out[i]++;
                c_in[v]++;
            }
        }
        solve();
    }
    return 0;
}