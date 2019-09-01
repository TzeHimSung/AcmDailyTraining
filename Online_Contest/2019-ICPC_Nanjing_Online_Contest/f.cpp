/* Contest nanjing_2019_online
 * Problem F
 * Team: Make One For Us
 */
#include <bits/stdc++.h>
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

int arr[100005], ans[100005];

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
    int T;
    T = read();
    while (T--) {
        int n, k;
        n = read();
        k = read();
        for (int i = 0; i < n; i++) {
            arr[i] = read();
        }
        //set <int> ruler;
        tree <int, null_type, less <int>, rb_tree_tag> ruler;
        for (int i = 0; i < k; i++) {
            ruler.insert(arr[i]);
        }
        vector <vector <int>> father(n + 1);
        for (int i = 0; i < n; i++) {
            if (i + k < n) {
                ruler.insert(arr[i + k]);
            }
            if (i - k - 1 >= 0) {
                ruler.erase(arr[i - k - 1]);
            }
            auto nxt = ruler.lower_bound(arr[i]);
            if (nxt != ruler.begin()) {
                auto val = *--nxt;
                father[val].emplace_back(arr[i]);
            } else {
                father[0].emplace_back(arr[i]);
            }
        }
        queue <pair <int, int>> q;
        q.emplace(make_pair(0, 0));
        while (!q.empty()) {
            auto t = q.front();
            q.pop();
            ans[t.first] = t.second;
            for (auto &e : father[t.first]) {
                q.emplace(make_pair(e, t.second + 1));
            }
        }
        for (int i = 1; i <= n; i++) {
            printf("%d%c", ans[i], i < n ? ' ' : '\n');
        }
    }
    return 0;
}