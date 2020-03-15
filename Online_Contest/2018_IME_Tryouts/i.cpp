#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define ff first
#define ss second
const int mod = 1e9 + 7;

ll mul(pii a, pii b, pii c) {
    c.ff = c.ff - a.ff, c.ss = c.ss - a.ss;
    a.ff = b.ff - a.ff, a.ss = b.ss - a.ss;
    return 1ll * a.ff * c.ss - 1ll * a.ss * c.ff;
}

pii a[1010], b[1010], c[1010];
int main() {
    int s, r, m, n;
    cin >> s >> r >> m;
    for (int i = 1; i <= s; i++)
        cin >> a[i].ff >> a[i].ss;
    for (int i = 1; i <= r; i++)
        cin >> b[i].ff >> b[i].ss;
    for (int i = 1; i <= m; i++)
        cin >> c[i].ff >> c[i].ss;
    a[s + 1] = a[1], b[r + 1] = b[1], c[m + 1] = c[1];
    cin >> n;
    while (n--) {
        pii x;
        cin >> x.ff >> x.ss;
        int gg = 0;
        for (int i = 1; i <= s; i++)
            if (mul(a[i], a[i + 1], x) < 0) {
                gg++;
                break;
            }
        if (!gg) {
            cout << "Sheena\n";
            continue;
        }
        gg = 0;
        for (int i = 1; i <= r; i++)
            if (mul(b[i], b[i + 1], x) < 0) {
                gg++;
                break;
            }
        if (!gg) {
            cout << "Rose\n";
            continue;
        }
        gg = 0;
        for (int i = 1; i <= m; i++)
            if (mul(c[i], c[i + 1], x) < 0) {
                gg++;
                break;
            }
        if (!gg) {
            cout << "Maria\n";
            continue;
        }
        cout << "Outside\n";
    }
}