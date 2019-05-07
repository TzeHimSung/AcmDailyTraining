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

const int maxn=4e5+10;
int n,a[maxn],ans=0;

int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++){
        scanf("%d",&a[i]); a[i+n]=a[i];
    }
    int cnt=0;
    for (int i=1;i<=2*n;i++){
        if (i==1){
            if (a[i]) cnt++; 
            continue;
        }
        if (!a[i]) cnt=0;
        else if (a[i-1]) cnt++; 
        else if (!a[i-1]) cnt=1;
        ans=max(ans,cnt);
    }
    printf("%d\n",ans);
    return 0;
}

