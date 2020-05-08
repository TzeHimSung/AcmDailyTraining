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

const int MAXN = 310;
const string alice = "Alice", bob = "Bob";
int n, remain;
string cur;
map<int, int>a;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> cur;
    remain = n;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        a[x]++;
    }
    int xianSheng = 0, xianBai = 0;
    for (auto i : a) {
        if (i.second % 3 == 1) {
            cout << alice << endl;
            return 0;
        }
    }
    while (1) {
        if (cur == bob) {

        }
    }
    for (auto i : a) {
        if (cur == bob) {
            if (i.second == 2) {
                i.second = 0;
                continue;
            } else if (i.second >= 5) {
                i.second = 3;
                continue;
            }
        }
    }
    return 0;
}