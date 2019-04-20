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

int n,m;
const int maxn=1e2;
int a[maxn];
set<int>s;

int main()
{
    s.clear();
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    for (int i=1;i<=m;i++)
    {
        int x; scanf("%d",&x); s.insert(x);
    }
    for (int i=1;i<=n;i++)
        if (s.count(a[i])) printf("%d ",a[i]);
    puts("");
    return 0;
}