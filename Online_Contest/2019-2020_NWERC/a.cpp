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

const int maxn = 1e6 + 10;
int n, week, score[maxn];
set<pair<int, ll>> scoreInfo[maxn]; // 以分数为下标，first是人的编号，second是
set<int> scores;
ll __rank[maxn];
double ans[maxn];

void init() {
    scores.insert(0);
    for (int i = 1; i <= n; i++) scoreInfo[0].insert(mp(i, 0));
}

int main() {
    scanf("%d%d", &n, &week);
    init();
    for (int i = 1; i <= week; i++) {
        int numOfPeople; scanf("%d", &numOfPeople);
        if (!numOfPeople) {
            int before = 0;
            for (auto j : scores) {
                int i = -j;
                __rank[i] += before + 1;
                before += scoreInfo[i].size();
            }
            continue;
        }
        while (numOfPeople--) {
            int currNum; scanf("%d", &currNum);
            int currManScore = score[currNum]; // sc是当前人的分数
            auto it = scoreInfo[currManScore].upper_bound(mp(currNum, -1));
            scoreInfo[currManScore + 1].insert(mp(currNum, it->second + __rank[currManScore] - __rank[currManScore + 1]));
            scoreInfo[currManScore].erase(it);
            score[currNum]++;
            if (scores.count(-score[currNum]) == 0) scores.insert(-score[currNum]);
            if (scoreInfo[currManScore].empty()) scores.erase(scores.find(-currManScore));
        }
        int before = 0;
        for (auto j : scores) { // 从高到低处理分数
            int i = -j;
            __rank[i] += before + 1;
            before += scoreInfo[i].size();
        }
    }
    for (auto j : scores) {
        int i = -j;
        for (auto p : scoreInfo[i]) ans[p.first] = 1.0 * (p.second + __rank[i]) / week;
    }
    for (int i = 1; i <= n; i++) printf("%.12f\n", ans[i]);
    return 0;
}