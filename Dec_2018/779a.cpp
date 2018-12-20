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

int n,a[6],b[6],x;

int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&x);
        a[x]++;
    }
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&x);
        b[x]++;
    }
    int ans=0;
    for (int i=1;i<=5;i++)
    {
        if ((a[i]+b[i])==0) continue;
        if ((a[i]+b[i])&1)
        {
            puts("-1");
            return 0;
        }
        ans+=abs(a[i]-b[i])/2;
    }
    printf("%d\n",ans/2);
    return 0;
}