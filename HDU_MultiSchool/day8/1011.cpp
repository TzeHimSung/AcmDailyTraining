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

struct _Class {
    int num, tea;
};

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector <_Class> _class(n);
        for (int i = 0; i < n; i++) {
            cin >> _class[i].num >> _class[i].tea;
        }
        sort(_class.begin(), _class.end(), [](_Class & a, _Class & b) {
            return a.tea == b.tea ? a.num > b.num : a.tea > b.tea;
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
            while (_class[i].num) {
                round++;
                int last = nxt; nxt = jump[nxt];
                if (nxt == i) break;
                if (_class[nxt].tea) {
                    int drink = min(_class[nxt].tea, _class[i].num);
                    _class[i].num -= drink, _class[nxt].tea -= drink;
                    ans += drink, cnt += drink;
                } else jump[last] = jump[nxt];
                if (round > n) break;
            }
            if (!cnt && _class[i].num) break;
        }
        cout << ans << endl;
    }
    return 0;
}