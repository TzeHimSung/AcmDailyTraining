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

int t;
const int maxn=1010;
char s[maxn];

int main() {
	scanf("%d",&t);
	while(t--){
		scanf("%s",s+1);
		int len=strlen(s+1);
		if (s[len]=='o') puts("FILIPINO");
		else if (s[len]=='u') puts("JAPANESE");
		else puts("KOREAN");
	}
    return 0;
}
