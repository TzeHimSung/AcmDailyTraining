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
#define lson curpos<<1
#define rson curpos<<1|1
/* namespace */
using namespace std;
/* header end */

const ll limit = 1LL << 32;
int n;
stack<ll>st;

int main() {
    cin >> n;
    ll curr = 0;
    st.push(1LL);
    while (n--) {
        string s; cin >> s;
        if (s == "add")
            curr += st.top();
        else if (s == "for") {
            ll x; cin >> x;
            st.push(min(limit, x * st.top()));
        } else if (s == "end")
            st.pop();
    }
    if (curr >= limit) puts("OVERFLOW!!!");
    else cout << curr << endl;
    return 0;
}