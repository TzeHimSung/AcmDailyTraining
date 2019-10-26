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

set<string>ss;
int n;

int main() {
    ss.clear();
    cin >> n;
    getchar();
    while (n--) {
        string op, book = "";
        cin >> op; getchar();
        getline(cin, book);
        if (op[0] == 'a') {
            ss.insert(book);
        } else {
            if (ss.count(book)) cout << "yes" << endl;
            else cout << "no" << endl;
        }
    }
    return 0;
}