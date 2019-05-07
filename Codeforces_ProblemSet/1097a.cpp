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

char a[3],b[3];
int flag=0;

int main()
{
    scanf("%s",a+1);
    for (int i=1;i<=5;i++){
        scanf("%s",b+1);
        if (a[1]==b[1] || a[2]==b[2]) flag=1;
    }

    if (!flag) puts("NO"); else puts("YES");
    return 0;
}

