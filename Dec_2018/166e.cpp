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

const int mod=1e9+7;
const int maxn=1e7+10;
int n,dp[maxn][5];

int main()
{
    mem(dp,0);
    scanf("%d",&n);
    dp[0][0]=1;
    for (int i=1;i<=n;i++)
        for (int j=0;j<4;j++)
            for (int k=0;k<4;k++)
            {
                if (j==k) continue;
                dp[i][j]+=dp[i-1][k];
                if (dp[i][j]>=mod) dp[i][j]%=mod;
            }
    printf("%d\n",dp[n][0]);
    return 0;
}