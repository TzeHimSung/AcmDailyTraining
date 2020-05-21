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

int t, n;
string s;

int check(int x) {
    if (x == 0 || x == 1) return 0;
    for (int i = 2; i <= (int)sqrt(x); i++) {
        if (x % i == 0) return 0;
    }
    return 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> s;
        int k;
        if (s[0] == 'i') k = 0;
        else if (s[10] == 't') k = 3;
        else if (s[11] == 'o') k = 4;
        else k = 5;
        if (k) {
            int tmp = k;
            while (k < n) k += tmp;
            cout << k - n << endl;
        } else {
            if (n <= 2) cout << 2 - n << endl;
            else if (n <= 3) cout << 3 - n << endl;
            else if (n <= 5) cout << 5 - n << endl;
            else if (n <= 7) cout << 7 - n << endl;
            else if (n <= 11) cout << 11 - n << endl;
            else if (n <= 13) cout << 13 - n << endl;
            else if (n <= 17) cout << 17 - n << endl;
        }
    }
    return 0;
}