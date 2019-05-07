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

ll ans=0;
int b,k;

int main()
{
    scanf("%d%d",&b,&k); 
    b=(b&1)?1:0;
    for(int i=k-1;i>=0;i--){
        int x; scanf("%d",&x);
        x=(x&1)?1:0;
        ans+=x*pow(b,i);
    }
    if (ans&1) puts("odd"); else puts("even");
    return 0;
}

