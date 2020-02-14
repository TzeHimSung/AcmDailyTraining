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

const int maxn=2e6+10;
int n,m;
ll ans=0;
struct Milk{
	int cost,num;
	bool operator<(const Milk& rhs)const{
		return cost<rhs.cost;
	}
}a[maxn];

int main() {
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++) scanf("%d%d",&a[i].cost, &a[i].num);
	sort(a+1,a+1+m);
	for (int i=1;i<=m && n; i++){
		if (!n) break;
		int delta=min(n,a[i].num);
		n-=delta;
		ans+=a[i].cost*delta;
	}
	printf("%lld\n",ans);
    return 0;
}

