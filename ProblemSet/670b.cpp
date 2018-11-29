#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    const int maxn=1e5+10;
    int a[maxn];
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    for (int i=1;i<=n;i++)
    {
        if (k-i>0) k-=i;
        else break;
    }
    printf("%d\n",a[k]);
    return 0;
}