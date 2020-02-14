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

const int maxn=110;
int n,total=0,maxone=0;
struct Student{
	char name[20],ganbu[2],xibu[2];
	int qimo, pingyi,paper,money;
}a[maxn];

int main() {
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%s%d%d%s%s%d",&a[i].name,&a[i].qimo,&a[i].pingyi,&a[i].ganbu,&a[i].xibu,&a[i].paper);
		if (a[i].qimo>80 && a[i].paper>=1) a[i].money+=8000;
		if (a[i].qimo>85 && a[i].pingyi>80) a[i].money+=4000;
		if (a[i].qimo>90) a[i].money+=2000;
		if (a[i].qimo>85 && a[i].xibu[0]=='Y') a[i].money+=1000;
		if (a[i].pingyi>80 && a[i].ganbu[0]=='Y') a[i].money+=850;
		total+=a[i].money;
		if (a[i].money>a[maxone].money) maxone=i;
	}
	printf("%s\n%d\n%d\n",a[maxone].name,a[maxone].money,total);
    return 0;
}

