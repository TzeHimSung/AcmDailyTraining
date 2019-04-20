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
#define init(a,b) fill(begin(a),end(a),b)
#define sot(a,b) sort(a+1,a+1+b)
#define rep(i,a) for(int i=1;i<=a;i++)
#define eps 1e-8
#define int int32_t
#define ll int64_t
//namespace
using namespace std;
//header end

const int maxn=1e6+10;
int n,m,a[maxn],b[maxn],f[maxn],s[maxn],t[maxn],sum=0,T,cnt=0;

int main()
{
    scanf("%d",&n);
    rep(i,n)
    {
        scanf("%d",&a[i]); sum+=a[i];
    }
    if (sum<n*2-2)
    {
        puts("NO");
        return 0;
    }
    rep(i,n)
    {
        if (a[i]>=2)
        {
            f[i]=1;
            b[++cnt]=i;
            if (cnt>=2)
            {
                s[cnt]=b[cnt-1];
                t[cnt]=i;
            }
        }
    }
    for (int i=1;i<=cnt;i++) a[b[i]]-=(i!=1)+(i!=cnt);
    printf("YES %d\n%d\n",min(cnt+1,n-1),n-1);
    int j=1,sign=0;
    rep(i,n)
    {
        if (a[i]==1 && !f[i])
        {
            if (!sign)
            {
                sign=1;
                a[b[cnt]]--; s[++cnt]=i; t[cnt]=b[cnt-1];
            }
            else
            {
                for (;!a[b[j]];j++);
                a[b[j]]--; s[++cnt]=i; t[cnt]=b[j];
            }
        }
    }
    for (int i=2;i<=n;i++) printf("%d %d\n",s[i],t[i]);
    return 0;
}