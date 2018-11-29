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
#define fi(a,b) fill(begin(a),end(a),b)
#define eps 1e-8

using namespace std;

const int maxn=1e5+10;
int n,m;
vector<int>a[maxn];
int b[maxn];

int main()
{
    fi(b,0);
    scanf("%d%d",&n,&m);
    for (int i=1;i<=m;i++) fi(a[i],0);
    for (int i=1;i<=n;i++)
    {
        int x,y; scanf("%d%d",&x,&y);
        a[x].pb(y);
    }
    for (int i=1;i<=m;i++)
        if (a[i].size()) sort(a[i].begin(),a[i].end());
    int ans=0;
    for (int i=1;i<=m;i++)
    {
        int len=a[i].size();
        if (!len) continue;
        int sum=0;
        for (int j=0;j<len;j++)
        {
            sum+=a[i][len-j-1];
            if (sum>0) b[j+1]+=sum;
            else break;
        }
    }
    for (int i=1;i<=maxn;i++) ans=max(ans,b[i]);
    printf("%d\n",ans);
    return 0;
}