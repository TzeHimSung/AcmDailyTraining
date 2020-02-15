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

int t,n;

int main() {
	scanf("%d",&t);
	while (t--){
		scanf("%d",&n);
		ll sum=0, k;
		for (int i=0;i<n;i++){
			ll x; scanf("%lld",&x);
			sum+=x;
			if (!i) k=x; else k^=x; 
		}
		if (sum==2*k) puts("0\n");
		else printf("2\n%lld %lld\n",k,sum+k);
	}
    return 0;
}

