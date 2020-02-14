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

map<char,char>m;
string a,b,c;

int main() {
	int flag=1;
	cin>>b>>a>>c;
	for (int i=0;i<b.size();i++){
		if (m.count(b[i]) && m[b[i]]!=a[i]) {
			flag=0;
			break;
		}
		m[b[i]]=a[i];
	}
	if (!flag || (int)m.size()!=26) return puts("Failed"),0;
	set<char>s;
	for (auto i:m) s.insert(i.second);
	if ((int)s.size()!=26) return puts("Failed"),0;
	for (auto i:c) cout<<m[i];
	puts("");
    return 0;
}

