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
//define
#define ll long long 
#define pb push_back
#define mp make_pair 
#define mem(a,b) memset(a,b,sizeof(a))
#define eps 1e-8

using namespace std;

const int maxn=1e2+10;
ll a[maxn];
ll n,ans=1;
int tot=0;

void getP()
{
    for (ll i=2;i*i<=n;i++)
    {
        if (n%i==0)
        {
            a[++tot]=i;
            while (n%i==0) n/=i;
        }
    }
    if (n>1) a[++tot]=n;
}

int main()
{
    scanf("%lld",&n);
    getP();
    for (int i=1;i<=tot;i++) ans*=a[i];
    printf("%lld\n",ans);
    return 0;
}