#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void get_next_position(
    int& curx, int& cury,
    const vector<int>& dx, const vector<int>& dy, int& dir,
    const vector<string>& a
) {
    int newx = curx + dx[dir];
    int newy = cury + dy[dir];
    if (0 <= newx && newx < 10 && 0 <= newy && newy < 10 && a[newx][newy] != '*') {
        curx = newx, cury = newy;
    }
    else {
        dir++;
        if (dir == 4) dir = 0;
    }
}

void solve() {
    vector<int>dx{ -1,0,1,0 }, dy{ 0,1,0,-1 };
    int fdir = 0, cdir = 0, fx, fy, cx, cy;
    map<pair<pair<int, int>, pair<int, int>>, int>vis;
    vector<string>a(10);
    for (int i = 0;i < 10;i++) {
        cin >> a[i];
        for (int j = 0;j < 10;j++) {
            if (a[i][j] == 'F') fx = i, fy = j;
            if (a[i][j] == 'C') cx = i, cy = j;
        }
    }
    int ans = 0;
    for (;;ans++) {
        // if (ans == 49) {
        //     cout << "49 here!\n";
        // }
        // cout << "fx = " << fx << ", fy = " << fy << ", cx = " << cx << ", cy == " << cy << '\n';
        if (fx == cx && fy == cy) {
            cout << ans << '\n';
            return;
        }
        vis[{{fx, fy}, { cx,cy }}]++;
        if (vis[{{ fx, fy }, { cx, cy }}] >= 4) {
            // cout << "break here!\nans = " << ans << '\n';
            // cout << "fx = " << fx << ", fy = " << fy << ", cx = " << cx << ", cy == " << cy << '\n';
            cout << "0\n";
            return;
        }
        get_next_position(fx, fy, dx, dy, fdir, a);
        get_next_position(cx, cy, dx, dy, cdir, a);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}