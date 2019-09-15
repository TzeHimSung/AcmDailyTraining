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

const int maxn = 110;
char s[maxn];
struct Light {
    int a, b, state;
    Light() {}
    Light(int _a, int _b, int _s): a(_a), b(_b), state(_s) {}
	
	void change(){
		if (state==1) state=0;
			else state=1;
	}
} a[maxn];
int n,ans=0;

int count(){
	int ret=0;
	for (int i=1;i<=n;i++)
		if (a[i].state==1) ret++;
	return ret;
}

int main() {
    scanf("%d", &n);
    scanf("%s", s + 1);
    for (int i = 1; i <= n; i++) {
        int x, y; scanf("%d%d", &x, &y);
        a[i].a = x; a[i].b = y; a[i].state = s[i] == '1' ? 1 : 0;
		if (a[i].state) ans++;
    }
	for (int i=1;i<=1000;i++){
		for (int j=1;j<=n;j++){
			if (i==a[j].b) a[j].change();
			else if (i>a[j].b && (i-a[j].b)%a[j].a==0) a[j].change();
		}
		ans=max(ans,count());
	}
	printf("%d\n",ans);
    return 0;
}
