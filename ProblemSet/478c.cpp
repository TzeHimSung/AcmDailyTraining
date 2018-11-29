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

ll a[3];

int main()
{
    scanf("%lld%lld%lld",&a[0],&a[1],&a[2]);
    sort(a,a+3); ll ans;
    a[2]=min(a[0]+a[1]<<1,a[2]);
    ans=(a[0]+a[1]+a[2])/3;
    printf("%lld\n",ans);
    return 0;
}