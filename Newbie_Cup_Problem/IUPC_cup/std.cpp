#define DATAGEN
// #define TEST
#include <iostream>
#include <string>

using namespace std;

const int maxn = 1e5 + 10;
int l[maxn], r[maxn];

int main() {
#ifdef DATAGEN
    // data gen
    freopen("./Newbie_Cup_Problem/IUPC_cup/data/2.in", "r", stdin);
    freopen("./Newbie_Cup_Problem/IUPC_cup/data/2.out", "w", stdout);
#endif // DATAGEN
    // 初始化
    int t;
    cin >> t;
    while (t--) {
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
#ifdef TEST
        for (int i = 0; i < n; i++) cout << s[i] << " ";
        cout << endl << endl;
        for (int i = 0; i < n; i++) cout << r[i] << " ";
        cout << endl;
        for (int i = 0; i < n; i++) cout << l[i] << " ";
        cout << endl;
#endif // TEST
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
#ifdef DATAGEN
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}