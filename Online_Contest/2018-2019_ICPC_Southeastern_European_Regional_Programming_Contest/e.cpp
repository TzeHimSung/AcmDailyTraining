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

const int MAXN = 1e6 + 10;
struct Fish {
    int x, y, leftMost, rightMost;
    Fish() {}
};
int coor[MAXN], maxRightMost = 0;

int main() {
    int n, m, l;
    scanf("%d%d%d", &n, &m, &l);
    vector<Fish> fishs(n);
    vector<int> num;
    vector<int> fishers(m);
    for (auto &fish : fishs) {
        scanf("%d%d", &fish.x, &fish.y);
        if (fish.y > l) continue;
        int maxDeltaX = l - fish.y;
        int leftMost = max(0, fish.x - maxDeltaX), rightMost = fish.x + maxDeltaX;
        num.push_back(leftMost), num.push_back(rightMost + 1);
        fish.leftMost = leftMost, fish.rightMost = rightMost + 1;
        maxRightMost = max(maxRightMost, rightMost + 1);
    }

    for (auto &fisher : fishers) {
        scanf("%d", &fisher);
        maxRightMost = max(fisher, maxRightMost);
        num.push_back(fisher);
    }

    sort(num.begin(), num.end());
    num.erase(unique(num.begin(), num.end()), num.end());
    maxRightMost = lower_bound(num.begin(), num.end(), maxRightMost) - num.begin();
    for (auto fish : fishs) {
        if (fish.y > l) continue;
        coor[lower_bound(num.begin(), num.end(), fish.leftMost) - num.begin()]++;
        coor[lower_bound(num.begin(), num.end(), fish.rightMost) - num.begin()]--;
    }

    int temp = 0;
    for (int i = 0; i <= maxRightMost; i++) {
        coor[i] += temp;
        temp = coor[i];
    }

    for (auto fisher : fishers)
        printf("%d\n", coor[lower_bound(num.begin(), num.end(), fisher) - num.begin()]);
    return 0;
}