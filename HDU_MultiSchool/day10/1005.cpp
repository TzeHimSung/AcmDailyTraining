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
        // for (auto e: data) {
        //     cout << e.x << ", " << e.y << endl;
        // }
        long long int ans = LONG_LONG_MAX;
        for (int i = 0; i < n; i++) {
            // cout << "for element " << i << " (" << data[i].x << ", " << data[i].y << "): \n";
            // cout << "select " << data[i].x << " as max_x" << endl;
            if (!(--cnt[data[i].y])) {
                cnt.erase(data[i].y);
            }
            long long int top = 0;
            if (!cnt.empty()) {
                top = cnt.rbegin()->first;
                // cout << "the y must be larger than " << top << endl;
                ans = min(ans, abs(top - data[i].x));
            }
            auto it = choice.lower_bound(data[i].x);
            if (it != choice.end()) {
                ans = min(ans, abs(max(top, *it) - data[i].x));
                // cout << "a possible choice is " << *it << ", the y can be " << max(top, *it) << endl;
            }
            if (it != choice.begin()) {
                advance(it, -1);
                ans = min(ans, abs(max(top, *it) - data[i].x));
                // cout << "a possible choice is " << *it << ", the y can be " << max(top, *it) << endl;
            }
            choice.insert(data[i].y);
            // cout << "now add " << data[i].y << " as a possible choice" << endl;
            // cout << "current min delta: " << ans << endl;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
