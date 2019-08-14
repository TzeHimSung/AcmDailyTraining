/* Codeforces Contest 2019_mutc_08
 * Problem K
 * Au: SJoshua
 */
#include <queue>
#include <cstdio>
#include <vector>
#include <string>
#include <list>
#include <iostream>
#include <algorithm>

using namespace std;

struct info {
    int p, m;
};

struct pnum {
    int id, num;
    bool operator < (const pnum &p) const {
        return id < p.id;
    }
};

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector <info> mise(n);
        for (int i = 0; i < n; i++) {
            cin >> mise[i].p >> mise[i].m;
        }
        sort(mise.begin(), mise.end(), [](info & a, info & b) {
            return a.m == b.m ? a.p > b.p : a.m > b.m;
        });
        long long int ans = 0;
        vector <int> jump(n);
        for (int i = 0; i < n - 1; i++) {
            jump[i] = i + 1;
        }
        jump[n - 1] = 0;
        for (int i = 0; i < n; i++) {
            int nxt = i;
            long long int cnt = 0, round = 0;
            while (mise[i].p) {
                round++;
                int last = nxt;
                nxt = jump[nxt];
                if (nxt == i) {
                    break;
                }
                if (mise[nxt].m) {
                    int drink = min(mise[nxt].m, mise[i].p);
                    mise[i].p -= drink;
                    mise[nxt].m -= drink;
                    ans += drink;
                    cnt += drink;
                } else {
                    jump[last] = jump[nxt];
                }
                if (round > n) {
                    break;
                }
            }
            if (!cnt && mise[i].p) {
                break;
            }
        }
        cout << ans << endl;
    }
    return 0;
}