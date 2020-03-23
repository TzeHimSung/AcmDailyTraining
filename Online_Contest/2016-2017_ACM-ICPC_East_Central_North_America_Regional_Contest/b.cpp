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

const int MAXN = 1e3 + 10;
int n, player[5], pos[MAXN];
map<int, string>name;
queue<int>waitQueue;
vector<pair<string, string>>ans;
string s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    player[1] = 3, player[2] = 2, player[3] = 1, player[4] = 4;

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s; name[i] = s;
        if (i > 4) waitQueue.push(i);
    }
    cin >> s;

    int maxPos = 0, len = s.size();
    for (int i = 0; i < len; i += pos[i]) {
        int j = i;
        while (s[j + 1] == s[i]) j++;
        pos[i] = j - i + 1;
        maxPos = max(j - i + 1, maxPos);
    }

    for (int i = 0; i < len; i++) {
        if (pos[i] == maxPos) {
            if (s[i] == 'W') {
                if (!i) ans.pb(mp(name[player[3]], name[player[1]]));
                else ans.pb(mp(name[player[1]], name[player[3]]));
            } else {
                if (!i) ans.pb(mp(name[player[2]], name[player[4]]));
                else ans.pb(mp(name[player[4]], name[player[2]]));
            }
        }
        if (s[i] == 'W') {
            waitQueue.push(player[4]);
            player[4] = player[2];
            player[2] = waitQueue.front();
            waitQueue.pop();
            swap(player[1], player[3]);
        } else {
            waitQueue.push(player[1]);
            player[1] = player[3];
            player[3] = waitQueue.front();
            waitQueue.pop();
            swap(player[2], player[4]);
        }
    }

    for (auto par : ans) {
        cout << par.first << " " << par.second << endl;
    }

    return 0;
}