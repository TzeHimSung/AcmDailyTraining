//basic
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <climits>
#include <algorithm>
#include <cmath>
#include <array>
#include <cstdint>
#include <iterator>
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
#define init(a,b) fill(begin(a),end(a),b)
#define eps 1e-8
#define pi 3.1415926

using namespace std;

const int maxn=1e6+10;
int n,m,a[maxn],b[maxn],f[maxn],s[maxn],t[maxn],sum=0,T,z=0;

int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]); sum+=a[i];
    }
    if (sum<n*2-2)
    {
        puts("NO");
        return 0;
    }
    for (int i=1;i<=n;i++)
    {
        if (a[i]>=2)
        {
            f[i]=1;
            b[++z]=i;
            if (z>=2)
            {
                s[z]=b[z-1];
                t[z]=i;
            }
        }
    }
    for (int i=1;i<=z;i++) a[b[i]]-=(i!=1)+(i!=z);
    printf("YES %d\n%d\n",min(z+1,n-1),n-1);
    int j=1,sign=0;
    for (int i=1;i<=n;i++)
    {
        if (a[i]==1 && !f[i])
        {
            if (!sign)
            {
                sign=1;
                a[b[z]]--; s[++z]=i; t[z]=b[z-1];
            }
            else
            {
                for (;!a[b[j]];j++);
                a[b[j]]--; s[++z]=i; t[z]=b[j];
            }
        }
    }
    for (int i=2;i<=n;i++) printf("%d %d\n",s[i],t[i]);
    return 0;
}