#include <bits/stdc++.h>
#define ll long long 

using namespace std;

const int mod=1e9+7;
const int maxn=1e5+10;
ll f[maxn];
int h[30];
int n,k,ans=0;
char s[maxn],t[maxn];

int main()
{
    memset(f,0,sizeof(f));
    scanf("%d%d",&k,&n);
    for (int i=0;i<26;i++) scanf("%d",&h[i]);
    scanf("%s",s+1);
    scanf("%s",t+1);
    for (int i=1;i<=n;i++)
        f[i]=((s[1]==t[i])+f[i-1])%mod;
    for (int i=2;i<=k;i++)
    {
        for (int j=n;j>=1;j--)
        {
            if (s[i]==t[j])
            {
                int pos=s[i-1]-'A';
                pos=h[pos];
                if (j-pos-1<1) f[j]=0;
                    else f[j]=f[j-pos-1];
            }
            else f[j]=0;
        }
        for (int j=1;j<=n;j++)
            f[j]=(f[j]+f[j-1])%mod;
    }
    printf("%lld\n",f[n]);
    return 0;
}