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

const int maxn=150010;
int n,a[maxn];

int main() {
	int t; scanf("%d",&t);
	while (t--){
		scanf("%d",&n);
		rep1(i,1,n) scanf("%d",&a[i]);
		stack<int>s; 
		while (!s.empty()) s.pop();
		s.push(a[n]);
		int ans=0;
		for (int i=n-1;i>0;i--){
			if (a[i]>s.top()) ans++;
			else if (a[i]<s.top()) s.push(a[i]);
		}
		printf("%d\n",ans);
	}
    return 0;
}
