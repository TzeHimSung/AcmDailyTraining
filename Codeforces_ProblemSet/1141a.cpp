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

int n,m;

int main()
{
    scanf("%d%d",&n,&m);
    if (m%n) puts("-1");
    else {
        int tmp=m/n,ans=0;
        while (tmp%2==0) tmp/=2,ans++;
        while (tmp%3==0) tmp/=3,ans++;
        if (tmp==1) printf("%d\n",ans); else puts("-1");
    }
    return 0;
}

