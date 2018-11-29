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

int n,s,t;
const int maxn=1e2+10;
int d[maxn];

int main()
{
    scanf("%d",&n); int sum=0;
    for (int i=1;i<=n;i++) {scanf("%d",&d[i]); sum+=d[i];}
    scanf("%d%d",&s,&t);
    if (s>t) swap(s,t);
    int ans=0;
    for (int i=s;i<=t-1;i++) ans+=d[i];
    ans=min(ans,sum-ans);
    printf("%d\n",ans);
    return 0;
}