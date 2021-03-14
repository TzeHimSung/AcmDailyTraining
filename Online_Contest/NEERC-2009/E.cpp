#include <bits/stdc++.h>

using namespace std;

const int maxn=4e4+10;
const int INF=1e6;
char c[105][3];
int flag[maxn],dp[maxn],nxt[maxn],n;

int dfs(int p)
{
    if (dp[p]!=-1) return dp[p];
    if (p==32767) return dp[p]=0;
    int s=32767-p;
    dp[p]=INF;
    for (int i=s;i;i=(i-1)&s)
    {
        if (flag[i]) continue;
        if (dp[p]>dfs(p+i)+1)
        {
            dp[p]=dp[p+i]+1;
            nxt[p]=p+i;
        }
    }
    return dp[p];
}

int main()
{
    while (scanf("%d",&n)!=EOF)
    {
        memset(flag,0,sizeof(flag));
        memset(dp,-1,sizeof(dp));
        memset(nxt,0,sizeof(nxt));
        for (int i=0;i<n;i++)
        {
            char s1[10],s2[10];
            scanf("%s%s",s1,s2);
            c[i][0]=s1[0]; c[i][1]=s2[0];
            int p=(1<<(s1[0]-'L')) | (1<<(s2[0]-'L'));
            for (int j=0;j<32768;j++)
                if ((j&p)==p) flag[j]=1;
        }
        printf("%d\n",dfs(0)-2);
        int depth[20],pos=0,d=0;
        while (pos!=32767)
        {
            int p=nxt[pos]-pos;
            for (int i=0;i<15;i++)
                if (p&(1<<i)) depth[i]=d;
            d++;
            pos=nxt[pos];
        }
        for (int i=0;i<n;i++)
        {
            int u=c[i][0]-'L';
            int v=c[i][1]-'L';
            if (depth[u]>depth[v]) printf("%c %c\n",c[i][1],c[i][0]);
                else printf("%c %c\n",c[i][0],c[i][1]);
        }
    }
    return 0;
}