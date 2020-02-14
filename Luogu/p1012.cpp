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

int cmp(const string& a, const string &b){
	return a+b>b+a;
}

int main() {
	cin>>n;
	vector<string>a(n);
	for (int i=0;i<n;i++) cin>>a[i];
	sort(a.begin(),a.end(),cmp);
	for (auto i:a) cout<<i;
	cout<<endl;
    return 0;
}

