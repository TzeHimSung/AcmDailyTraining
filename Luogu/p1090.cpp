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

int n;
priority_queue<int,vector<int>,greater<int>>q;

int main() {
	while (!q.empty()) q.pop();
	scanf("%d",&n);
	while (n--){
		int x; scanf("%d",&x);
		q.push(x);
	}
	int ans=0;
	while ((int)q.size()!=1){
		int x=q.top(),y;
		q.pop(); y=q.top(); q.pop();
		ans+=x+y;
		q.push(x+y);
	}
	printf("%d\n",ans);
    return 0;
}

