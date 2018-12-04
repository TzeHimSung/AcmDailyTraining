#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>

#include <vector>
#include <set>
#include <map>

#define ll long long 
#define pb push_back

using namespace std;

ll a,b,k,ans;
int t;

int main()
{
	scanf("%d",&t);
	while (t--)
	{
		scanf("%lld%lld%lld",&a,&b,&k);
		ans=k/2*(a-b);
		if (k&1) ans+=a;
		printf("%lld\n",ans);
	}
	return 0;
}