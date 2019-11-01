#include <iostream>
#include <string>

using namespace std;

const int maxn = 1e5 + 10;
int l[maxn], r[maxn];

int main() {
    // freopen("./Newbie_Cup_Problem/IUPC_cup/data/2.in", "r", stdin);
    // freopen("./Newbie_Cup_Problem/IUPC_cup/data/2.out", "w", stdout);

    int t;
    cin >> t;
    while (t--) {
        // 初始化
        for (int i = 0; i < maxn; i++)
            l[i] = r[i] = 0;
        int n;
        string s;
        cin >> n >> s;
        for (int i = 0; i < n; i++)
            if (s[i] == '1') {
                l[i] = 1;
                if (i > 0) l[i] += l[i - 1];
            }
        for (int i = n - 1; i >= 0; i--)
            if (s[i] == '1') {
                r[i] = 1;
                if (i + 1 < n) r[i] += r[i + 1];
            }
        int ans = 0, total = 0;
        for (int i = 0; i < n; i++)
            if (s[i] == '1') total++;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') continue;
            int currAns = 1;
            if (i > 0) currAns += l[i - 1];
            if (i + 1 < n) currAns += r[i + 1];
            ans = max(ans, currAns);
        }
        ans = min(ans, total);
        if (total == n) ans = n;
        cout << ans << endl;
    }
    return 0;
}