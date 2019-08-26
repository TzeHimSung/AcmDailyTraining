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

const int maxn=2e3+10;
int n,a[maxn],mul=0,ans=int_inf;
map<int,int>m;

int main() {
	m.clear();
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		m[a[i]]++;
	}
	for (auto i:m)
		if (i.second>1) mul++;
	if (!mul) return puts("0"),0;
	for (int i=1;i<=n;i++){
		int ret=-1,tmp=mul;
		for (int j=i;j<=n;j++){
			ret=j;
			if (--m[a[j]]==1) tmp--;
			if (!tmp){
				ans=min(ans,j-i+1);
				break;
			}
		}
		for (int j=i;j<=ret;j++) m[a[j]]++;
	}
	printf("%d\n",ans);
    return 0;
}
