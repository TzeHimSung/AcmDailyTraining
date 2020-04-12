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

const int MAXN = 1e5 + 10;
int n, m, days, knowEach[MAXN];
vector<int>g[MAXN];
set<int>canBeKill;

int main() {
    for (int i = 0; i < MAXN; i++) knowEach[i] = 0;
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    cin >> days;
    for (int day = 1; day <= days; day++) {
        int die; cin >> die;
        if (day == 1) {
            for (auto people : g[die]) {
                canBeKill.insert(people);
                knowEach[people] = 1;
            }
        } else {
            for (auto people : g[die]) {
                knowEach[people] = 1;
            }
            if (knowEach[die]) {
                if (canBeKill.find(die) != canBeKill.end()) canBeKill.erase(die);
            } else {
                set<int>tmp;
                for (auto people : g[die]) {
                    if (canBeKill.find(people) != canBeKill.end()) tmp.insert(people);
                }
                canBeKill = tmp;
            }
        }
        if (canBeKill.size() == 1) {
            cout << day << " " << *canBeKill.begin() << endl;
            return 0;
        }
    }
    cout << "-1" << endl;
    return 0;
}