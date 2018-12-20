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
//namespace
using namespace std;
//header end

int n;
const int maxn=1e3+10;
int a[maxn],vis[maxn];

int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    int curr=0,ans=0;
    init(vis,0);
    while (1)
    {
        if (ans%2==0)
        {
            for (int i=1;i<=n;i++)
                if (!vis[i] && a[i]<=curr)
                {
                    vis[i]=1;
                    curr++;
                }
        }
        else
        {
            for (int i=n;i>=1;i--)
                if (!vis[i] && a[i]<=curr)
                {
                    vis[i]=1;
                    curr++;
                }
        }
        if (curr==n) break;
        ans++;
    }
    printf("%d\n",ans);
    return 0;
}