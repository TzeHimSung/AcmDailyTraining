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

int n,m,ans=0,curr=0;

int main() {
	scanf("%d%d",&n,&m);
	while (n--){
		int x; scanf("%d",&x);
		if (curr+x<=m) curr+=x;
		else{
			curr=x;
			ans++;
		}
	}
	if (curr) ans++;
	printf("%d\n",ans);
    return 0;
}

