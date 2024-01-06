#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    map<pair<int, int>, int>relation = {
        {{0,0}, 0},
        {{0,1}, -1},
        {{0,2}, 1},
        {{0,3}, 1},
        {{0,4}, -1},
        {{1,0}, 1},
        {{1,1}, 0},
        {{1,2}, -1},
        {{1,3}, 1},
        {{1,4}, -1},
        {{2,0}, -1},
        {{2,1}, 1},
        {{2,2}, 0},
        {{2,3}, -1},
        {{2,4}, 1},
        {{3,0}, -1},
        {{3,1}, -1},
        {{3,2}, 1},
        {{3,3}, 0},
        {{3,4}, 1},
        {{4,0}, 1},
        {{4,1}, 1},
        {{4,2}, -1},
        {{4,3}, -1},
        {{4,4}, 0}
    };
    int n, na, nb;
    cin >> n >> na >> nb;
    vector<int> a(na), b(nb);
    for (int i = 0;i < na;i++) cin >> a[i];
    for (int i = 0;i < nb;i++) cin >> b[i];
    int pa = 0, pb = 0, sa = 0, sb = 0;
    while (n--) {
        int result = relation[{a[pa++], b[pb++]}];
        if (pa == na) pa = 0;
        if (pb == nb) pb = 0;
        if (result == 1) sa++;
        else if (result == -1) sb++;
    }
    cout << sa << ' ' << sb;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}