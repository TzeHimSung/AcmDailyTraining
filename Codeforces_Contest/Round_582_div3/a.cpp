/* basic header */
#include <bits/stdc++.h>
/* define */
#define ll long long
#define dou double
#define pb emplace_back
#define mp make_pair
#define sot(a,b) sort(a+1,a+1+b)
#define rep1(i,a,b) for(int i=a;i<=b;++i)
#define rep0(i,a,b) for(int i=a;i<b;++i)
#define eps 1e-8
#define int_inf 0x3f3f3f3f
#define ll_inf 0x7f7f7f7f7f7f7f7f
#define lson (curpos<<1)
#define rson (curpos<<1|1)
/* namespace */
using namespace std;
/* header end */

const int maxn=110;
int n,a[maxn];

int main() {
	scanf("%d",&n);
	int aa=0,bb=0;
	rep1(i,1,n){
		int x; scanf("%d",&x);
		if (x&1) aa++; else bb++;
	}
	printf("%d\n",min(aa,bb));
    return 0;
}
