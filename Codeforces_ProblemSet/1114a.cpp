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

int x,y,z,a,b,c;

int main()
{
    scanf("%d%d%d%d%d%d",&x,&y,&z,&a,&b,&c);
    if (a<x) return puts("NO"),0;
    a-=x;
    if (a+b<y) return puts("NO"),0;
    if (a>=y) a-=y; else b-=y-a,a=0;
    if (a+b+c<z) return puts("NO"),0;
    puts("YES");
    return 0;
}

