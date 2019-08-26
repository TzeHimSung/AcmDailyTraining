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
        map <long long int, int> cnt;
        set <long long int> choice;
        for (int i = 0; i < n; i++) {
            scanf("%lld %lld", &data[i].x, &data[i].y);
            cnt[data[i].y]++;
        }
        sort(data.begin(), data.end(), [](info & a, info & b) -> bool {
            return a.x < b.x;
        });
        long long int ans = LONG_LONG_MAX;
        for (int i = 0; i < n; i++) {
            if (!(--cnt[data[i].y])) {
                cnt.erase(data[i].y);
            }
            long long int top = 0;
            if (!cnt.empty()) {
                top = cnt.rbegin()->first;
                ans = min(ans, abs(top - data[i].x));
            }
            auto it = choice.lower_bound(data[i].x);
            if (it != choice.end()) {
                ans = min(ans, abs(max(top, *it) - data[i].x));
            }
            if (it != choice.begin()) {
                advance(it, -1);
                ans = min(ans, abs(max(top, *it) - data[i].x));
            }
            choice.insert(data[i].y);
        }
        printf("%lld\n", ans);
    }
    return 0;
}
