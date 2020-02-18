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
map<string, int>m;
string s;

int main() {
    cin >> n; int mm = n;
    while (mm--) {
        cin >> s;
        m[s]++;
    }
    for (auto i : m) {
        if (i.second > n - i.second) {
            cout << i.first << endl;
            return 0;
        }
    }
    cout << "NONE" << endl;
    return 0;
}