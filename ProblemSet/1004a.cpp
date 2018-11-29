//basic
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <climits>
#include <algorithm>
#include <cmath>
//STL
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>

#define ll long long 
#define pb push_back
#define mp make_pair 

using namespace std;

const int maxn=1e2+10;
int a[maxn];
int n,d,ans=2;

int main()
{
    scanf("%d%d",&n,&d);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    sort(a+1,a+1+n);
    for (int i=2;i<=n;i++)
    {
        int x=a[i]-a[i-1];
        if (x>2*d) ans+=2;
        else if (x==2*d) ans++;
    }
    printf("%d\n",ans);
    return 0;
}