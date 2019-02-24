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

const int maxn=1e5+10;
int n,a[maxn];

int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    int ans=a[1]+1;
    for (int i=2;i<=n;i++)
    {
        if (a[i]<a[i-1]) ans+=a[i-1]-a[i]+2; //plus 2 means jump and eat
        else if (a[i]==a[i-1]) ans+=2;
        else ans+=a[i]-a[i-1]+2;
    }
    printf("%d\n",ans);
    return 0;
}