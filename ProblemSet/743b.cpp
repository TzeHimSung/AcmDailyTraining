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

ll n,k;

ll dfs(ll n,ll k)
{
    if (n==1) return n;
    ll t=(1LL<<(n-1));
    if (k==t) return n;
    if (k>t) return dfs(n-1,k-t);
    return dfs(n-1,k);
}

int main()
{
    scanf("%lld%lld",&n,&k);
    printf("%lld\n",dfs(n,k));
    return 0;
}