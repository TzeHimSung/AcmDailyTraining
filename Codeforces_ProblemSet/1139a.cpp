#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define sot(a,b) sort(a+1,a+1+b)
#define rep(i,a,b) for (int i=a;i<=b;i++)
#define eps 1e-8
#define int_inf (1<<30)-1
#define ll_inf (1LL<<62)-1
#define lson curPos<<1
#define rson curPos<<1|1

using namespace std;

const int maxn=6e4+5e3+10;
int n;
ll ans=0;
char s[maxn];

int main()
{
    scanf("%d%s",&n,s+1);
    rep(i,1,n)
        if ((s[i]-'0')%2==0) ans+=i;
    printf("%lld\n",ans);
    return 0;
}

