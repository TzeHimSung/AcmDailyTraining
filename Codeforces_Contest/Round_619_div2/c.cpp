/* basic header */
#include <bits/stdc++.h>
/* define */
#define ll long long
#define pb emplace_back
#define mp make_pair
#define eps 1e-8
#define lson (curpos<<1)
#define rson (curpos<<1|1)
/* namespace */
using namespace std;
/* header end */

int t;
ll n,m;

int main() {
	scanf("%d",&t);
	while (t--){
		scanf("%lld%lld",&n,&m);
		ll ans=(n+1)*n/2, cnt=(n-m)/(m+1);
		ans-=cnt*(cnt+1)/2*(m+1-(n-m)%(m+1))+(cnt+1)*(cnt+2)/2*((n-m)%(m+1));
		printf("%lld\n",ans);
	}
    return 0;
}
