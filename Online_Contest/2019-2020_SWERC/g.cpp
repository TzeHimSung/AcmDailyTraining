#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
typedef long long ll;
typedef pair<int, int> pii;

map<string, int> m;
int w[210][210], cur[210];
int a[100010];
string ans[210];
int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int s, l, n, cnt = 0;
    cin >> s >> l >> n;
    for (int i = 1; i <= s; i++) {
        string str;
        cin >> str;
        m[str]++;
        cur[i] = 1;
    }
    for (auto &i : m) {
        i.ss = ++cnt;
        ans[cnt] = i.ff;
    }
    for (int i = 1; i <= l; i++) {
        string x, y;
        cin >> x >> y;
        int xx = m[x], yy = m[y];
        w[xx][yy] = w[yy][xx] = 1;
    }
    for (int i = 1; i <= n; i++) {
        string str;
        cin >> str;
        a[i] = m[str];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= s; j++) {
            while (cur[j] <= n && (a[cur[j]] == -1 || w[j][a[cur[j]]]))
                cur[j]++;
            if (a[cur[j]] == j) {
                cout << ans[j] << " ";
                a[cur[j]] = -1;
                break;
            }
        }
    }
}