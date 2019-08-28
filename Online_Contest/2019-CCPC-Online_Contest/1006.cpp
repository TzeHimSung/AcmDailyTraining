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

int main() {
	int n,m; scanf("%d%d",&n,&m);
	vector<int> cards(n);
	stack<int>s; 
	vector<bool> vis(n+1);
	for (auto &i:cards) scanf("%d",&i);
	for (int i=0;i<m;i++){
		int op; scanf("%d",&op);
		s.push(op);
	}
	while (!s.empty()){
		if (!vis[s.top()]){
			vis[s.top()]=true;
			printf("%d ",s.top());
		}
		s.pop();
	}
	for (auto i:cards)
		if (!vis[i]) printf("%d ",i);
    return 0;
}

