#include<bits/stdc++.h>
using namespace std;
int a[200010],b[200010];
int dp[200010][2];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,c;
        scanf("%d%d",&n,&c);
        for(int i=2;i<=n;i++)scanf("%d",&a[i]);
        for(int i=2;i<=n;i++)scanf("%d",&b[i]);
        dp[2][1]=a[2]+c,dp[2][0]=b[2];
        for(int i=3;i<=n;i++){
            dp[i][1]=min(dp[i-1][0]+c,dp[i-1][1])+a[i];
            dp[i][0]=min(dp[i-1][0],dp[i-1][1])+b[i];
        }
        printf("%d\n",min(dp[n][0],dp[n][1]));
    }
}