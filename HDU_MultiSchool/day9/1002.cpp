/* Codeforces Contest 2019_mutc_09
 * Problem B
 * Au: SJoshua
 */
#include <unordered_map>
#include <cctype>
#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

class binTree {
public:
    binTree(vector <int> &a) {
        bit.resize(a.size() + 1);
        for (int i = 1; i <= a.size(); i++) {
            bit[i] = a[i - 1];
            for (int j = i - 2; j >= i - lowbit(i); j--) {
                bit[i] += a[j];
            }
        }
    }
    void edit(int index, int delta) {
        for (int i = index; i < bit.size(); i += lowbit(i)) {
            bit[i] += delta;
        }    
    }
    int query(int index) {
        int ret = 0;
        for (int i = index; i > 0; i -= lowbit(i)) {
            ret += bit[i];
        }
        return ret;
    }
private:
    int lowbit(int num) {
        return num & (-num);
    }
    vector <int> bit;
};

struct event {
    int type, line, col; // 1: in / 2: query(up) / 3: query(down) / 4: out
};

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
        int n, m, k;
        m = read();
        n = read();
        k = read();
        vector <event> events;
        vector <int> ints(2 * k);
        for (int i = 0; i < k; i++) {
            int x, y;
            char d;
            y = read();
            x = read();
            scanf(" %c", &d);
            ints[i] = x;
            ints[i + k] = y;
            switch (d) {
                case 'L':
                    events.push_back({1, x, 0});
                    events.push_back({4, x, y});
                    break;
                case 'R':
                    events.push_back({1, x, y});
                    events.push_back({4, x, m});
                    break;
                case 'U':
                    events.push_back({2, x, y});
                    break;
                case 'D':
                    events.push_back({3, x, y});
                    break;
            }
        }
        ints.push_back(0);
        ints.push_back(m);
        ints.push_back(n);
        unordered_map <int, int> mp;
        sort(ints.begin(), ints.end());
        ints.resize(unique(ints.begin(), ints.end()) - ints.begin());
        for (int i = 0; i < ints.size(); i++) {
            mp[ints[i]] = i + 1;
        }
        for (auto &e: events) {
            e.line = mp[e.line];
            e.col = mp[e.col];
        }
        sort(events.begin(), events.end(), [](event &a, event &b) -> bool {
            return a.col == b.col ? a.type < b.type : a.col < b.col;
        });
        long long int ans = 1;
        vector <int> arr(ints.size() + 1);
        auto bt = binTree(arr);
        for (auto e: events) {
            switch (e.type) {
                case 1:
                    bt.edit(e.line, 1);
                    break;
                case 2:
                    ans += bt.query(mp[n]) - bt.query(e.line - 1);
                    break;
                case 3:
                    ans += bt.query(e.line);
                    break;
                case 4:
                    bt.edit(e.line, -1);
                    break;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
