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

const int maxn=5e3+10;
int n,m;
struct Player{
	int id,mark;
	bool operator<(const Player &rhs)const{
		return mark!=rhs.mark?mark>rhs.mark:id<rhs.id;
	}
}a[maxn];

int main() {
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d%d",&a[i].id,&a[i].mark);
	sort(a+1,a+1+n);
	int mark=a[int(m*1.5)].mark;
	int pos;
	for (pos=1;a[pos].mark>=mark;pos++);
	pos--;
	printf("%d %d\n",mark,pos);
	for (int i=1;i<=pos;i++) printf("%d %d\n",a[i].id,a[i].mark);
    return 0;
}

