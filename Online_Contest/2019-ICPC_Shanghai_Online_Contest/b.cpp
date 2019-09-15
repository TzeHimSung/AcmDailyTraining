/* Contest shanghai_2019_online
 * Problem B
 * Team: Make One For Us
 */
#include <bits/stdc++.h>

using namespace std;

int read(void) {
    char ch;
    do {
        ch = getchar();
    } while (!isdigit(ch));
    int ret = 0;
    while (isdigit(ch)) {
        ret *= 10;
        ret += ch - '0';
        ch = getchar();
    }
    return ret;
}

int main(void) {
    int T = read();
    for (int c = 1; c <= T; c++) {
        int n = read(), m = read();
        vector <int> events(m * 2);
        int last = 1000000;
        for (int i = 0; i < m; i++) {
            int a = read(), b = read();
            events[i] = a;
            events[i + m] = b + 1;
            last = min({last, a, b + 1});
        }
        last--;
        events.emplace_back(last);
        events.emplace_back(last);
        sort(events.begin(), events.end());
        long long int ans = 0;
        bool light = false;
        bool flag = false;
        int cur = -2;
        for (unsigned i = 0; i < events.size(); i++) {
            int e = events[i];
            if (e != cur) {
                flag = light;
            }
            light = light ? false : true;
            if (i == events.size() - 1 || e != events[i + 1]) {
                if (flag) {
                    ans += e - last;
                }
                last = e;
            }
            cur = e;
        }
        printf("Case #%d: %lld\n", c, ans);
    };
    return 0;
}