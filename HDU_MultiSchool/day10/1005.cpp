/* Codeforces Contest 2019_mutc_10
 * Problem E
 * Au: SJoshua
 */
#include <set>
#include <map>
#include <cstdio>
#include <vector>
#include <string>
#include <climits>
#include <iostream>
#include <algorithm>

using namespace std;

struct info {
    long long int x, y;
};

int main(void) {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        vector <info> data(n);
        map <long long int, int> cnt; // counter of y
        set <long long int> usedY;
        for (int i = 0; i < n; i++) {
            scanf("%lld %lld", &data[i].x, &data[i].y);
            cnt[data[i].y]++;
        }
        sort(data.begin(), data.end(), [](info & a, info & b) -> bool {
            return a.x < b.x; // sort by x
        });
        long long int ans = LONG_LONG_MAX;
        for (int i = 0; i < n; i++) { // enum each number pair
            if (!(--cnt[data[i].y])) { // if y remain one time
                cnt.erase(data[i].y);
            }
            long long int top = 0;
            if (!cnt.empty()) { // top is the largest y
                top = cnt.rbegin()->first;
                ans = min(ans, abs(top - data[i].x)); // ans up limit
            }
            auto it = usedY.lower_bound(data[i].x);
            if (it != usedY.end()) {
                ans = min(ans, abs(max(top, *it) - data[i].x));
            }
            if (it != usedY.begin()) {
                advance(it, -1);
                ans = min(ans, abs(max(top, *it) - data[i].x));
            }
            usedY.insert(data[i].y);
        }
        printf("%lld\n", ans);
    }
    return 0;
}
