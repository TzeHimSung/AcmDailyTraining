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
#define lson (minpos<<1)
#define rson (minpos<<1|1)
/* namespace */
using namespace std;
/* header end */

int t;
string a,b;

int main() {
	cin>>t;
	while (t--){
		cin>>a>>b;
		if (a<b){
			cout<<a<<'\n';
			continue;
		}
		string s=a;
		sort(s.begin(),s.end());
		int flag=0;
		for (int i=0;i<(int)a.size();i++){
			// current char is not at the best position
			if (a[i]>s[i]){
				// it can swap with the back char only
				for (int j=i+1;j<(int)a.size();j++){
					swap(a[i],a[j]);
					if (a<b){
						cout<<a<<'\n';
						flag=1;
						i=(int)a.size();
						break;
					}
					swap(a[i],a[j]);
				}
			}
		}
		if (!flag) puts("---");
	}
    return 0;
}
