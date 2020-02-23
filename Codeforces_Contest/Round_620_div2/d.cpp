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

const int maxn = 2e5 + 10;
int t, n, m, a[maxn], b[maxn];
string s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> s; m = n;
        for (int i = 0; i < n; i++) {
            int len = 1;
            while (i < s.size() && s[i] == '<') {
                len++; i++;
            }
            for (int j = i; j > i - len; j--) a[j] = m--;
        }
        for (int i = 0; i < n; i++) cout << a[i] << " ";
        cout << endl;
        m = 1;
        for (int i = 0; i < n; i++) {
            int len = 1;
            while (i < s.size() && s[i] == '>') {
                len++; i++;
            }
            for (int j = i; j > i - len; j--) b[j] = m++;
        }
        for (int i = 0; i < n; i++) cout << b[i] << " ";
        cout << endl;
    }
    return 0;
}