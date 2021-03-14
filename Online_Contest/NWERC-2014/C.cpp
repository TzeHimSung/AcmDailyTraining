#include <bits/stdc++.h>

using namespace std;

const int INF=2e7+10;
const int maxn=1e4+10;
int dp[maxn][22],a[maxn],ans=INF,n,d;

int main()
{
    memset(dp,0,sizeof(dp));
    memset(a,0,sizeof(a));
    scanf("%d%d",&n,&d);
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        dp[i][0]+=dp[i-1][0]+a[i];
    }
    for (int j=1;j<=d;j++)
    {
        for (int i=1;i<=n;i++)
        {
            dp[i][j]=INF;
            if (dp[i-1][j])
                dp[i][j]=min(dp[i-1][j]+a[i],dp[i][j]);
            if (dp[i-1][j-1])
                dp[i][j]=min(dp[i][j],(dp[i-1][j-1]+5)/10*10+a[i]);
        }
    }
    for (int i=0;i<=d;i++)
        ans=min(ans,(dp[n][i]+5)/10*10);
    printf("%d\n",ans);
    return 0;
} 