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

const int maxn=2e5+10;
int a[maxn],n,x,maxx,minn,flag=1,c=0;

int main()
{
    scanf("%d%d",&n,&x); maxx=minn=x,a[x]++;
    for (int i=1;i<n;i++){
        scanf("%d",&x); 
        if (!flag) continue;
        if (++a[x]>2) flag=0;
            else if (a[x]==2) c++;
        if (x>maxx) maxx=x; else if (x<minn) minn=x;
    }
    if (!flag) return puts("NO"),0;
    puts("YES"); printf("%d\n",c);
    for (int i=minn;i<=maxx;i++)
        if (a[i]==2) printf("%d ",i);
    puts("");
    printf("%d\n",n-c);
    for (int i=maxx;i>=minn;i--)
        if (a[i]) printf("%d ",i);
    puts("");
    return 0;
}

