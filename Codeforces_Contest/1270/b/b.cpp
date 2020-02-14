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

const int maxn=2e5+10;
int t,n,a[maxn];

int main() {
	scanf("%d",&t);
	while (t--){
		int maxx=-1, minn=INT_MAX;
		scanf("%d",&n);
		for (int i=1;i<=n;i++) {
			scanf("%d",&a[i]);
			maxx=max(maxx,a[i]), minn=min(minn,a[i]);
		}
		// printf("maxx = %d, minn = %d\n",maxx,minn);
		if (maxx==minn){
			puts("NO");
			continue;
		}
		set<int>minpos,maxpos; minpos.clear(); maxpos.clear();
		for (int i=1;i<=n;i++)
			if (a[i]==minn) minpos.insert(i);
			else if (a[i]==maxx) maxpos.insert(i);
		int flag=0;
		for (auto i:minpos){
			for (auto j:maxpos){
				// printf("i = %d, j = %d\n",i,j);
				if (maxx-minn>=abs(i-j)+1){
					flag=1;
					printf("YES\n%d %d\n",min(i,j),max(i,j));
					goto mark;
				}
			}
		}
mark:
		if (!flag) puts("NO");
	}
    return 0;
}
