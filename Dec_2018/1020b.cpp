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

const int maxn=1e3+10;
int n,a[maxn],vis[maxn];

int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    for (int i=1;i<=n;i++)
    {
        mem(vis,0);
        int curr=i;
        while (1)
        {
            vis[curr]++;
            if (vis[curr]==2) break;
            curr=a[curr];
        }
        printf("%d%c",curr,i==n?'\n':' ');
    }
    return 0;
}