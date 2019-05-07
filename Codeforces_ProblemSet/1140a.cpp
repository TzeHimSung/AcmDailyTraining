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

const int maxn=1e4+10;
int n,a[maxn],ans=0;

int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    for (int i=1;i<=n;i++,ans++){
        int lim=a[i];
        for (int j=i;j<=lim;j++)
            lim=max(lim,a[j]);
        i=lim;
    }
    printf("%d\n",ans);
    return 0;
}

