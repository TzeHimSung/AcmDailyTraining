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

const int maxn = 110, maxl = 60;
string huiwen = "", ans = "";
int n, m;
set<string>s;
map<string, string>mm;

bool isHuiwen(string curs) {
    int p = -1, q = (int)curs.size();
    while (1) {
        p++, q--;
        if (p >= q) break;
        if (curs[p] != curs[q]) return false;
    }
    return true;
}

int main() {
    s.clear(), mm.clear();
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        string x; cin >> x;
        s.insert(x);
    }
    for (auto i : s) {
        if (isHuiwen(i)) {
            if ((int)i.size() > (int)huiwen.size()) huiwen = i;
            continue;
        }
        string tmp = i;
        reverse(tmp.begin(), tmp.end());
        if (s.count(tmp)) {
            s.erase(tmp);
            mm[i] = tmp;
        }
    }
    stack<string>st;
    while (!st.empty()) st.pop();
    for (auto i : mm) {
        ans += i.first;
        st.push(i.first);
    }
    ans += huiwen;
    while (!st.empty()) {
        ans += mm[st.top()];
        st.pop();
    }
    cout << (int)ans.size() << endl << ans << endl;
    return 0;
}