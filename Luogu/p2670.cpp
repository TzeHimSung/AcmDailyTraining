#include <bits/stdc++.h>

using namespace std;
using ll = long long;

bool isValid(int x, int y, int n, int m) {
    return 0 <= x && x < n && 0 <= y && y < m;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string>a(n);
    vector<vector<int>>b(n, vector<int>(m, 0));
    vector<int>dx{ -1,0,1,0,-1,-1,1,1 }, dy{ 0,-1,0,1,-1,1,-1,1 };
    for (int i = 0;i < n;i++) {
        cin >> a[i];
    }
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < m;j++) {
            if (a[i][j] == '*') continue;
            for (int k = 0;k < 8;k++) {
                int curx = i + dx[k], cury = j + dy[k];
                if (isValid(curx, cury, n, m) && a[curx][cury] == '*') {
                    b[i][j]++;
                }
            }
        }
    }
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < m;j++) {
            if (a[i][j] == '?') cout << b[i][j];
            else cout << a[i][j];
        }
        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}