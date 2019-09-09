/* Contest xuzhou_2019_online
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
    };
    return ret;
}

struct range {
    int l, r;
    bool operator < (const range &r) const {
        return l < r.l;
    }
};

int main(void) {
    int n, q;
    n = read();
    q = read();
    unordered_map <int, int> mp;
    vector <pair <int, int>> query(q);
    set <range> st;
    for (int i = 0; i < q; i++) {
        query[i].first = read();
        query[i].second = read();
    }
    for (int i = 0; i < q; i++) {
        auto t = query[i].second;
        if (query[i].first == 1) {
            auto next = st.upper_bound({t, 0});
            range nxt = {t, t};
            if (next != st.begin()) { // 它有前驱(prev)也有后继(next)
                auto prev = next;
                prev--;
                if (prev->l <= t && t <= prev->r) { // 已经存在这样的区间
                    continue;
                } else { // 需要进行更新
                    if (prev->r + 1 == t) { // 可以和左侧合并
                        nxt.l = prev->l;
                        st.erase(prev);
                    }
                }
            }
            if (next != st.end()) {
                if (next->l == t + 1) { // 可以和右侧合并
                    nxt.r = next->r;
                    st.erase(next);
                }
            }
            st.emplace(nxt);

        } else if (query[i].first == 2) {
            // 是否被包含？
            auto next = st.upper_bound({t, 0});
            if (next != st.begin()) {
                auto prev = next;
                prev--;
                if (prev->l <= t && t <= prev->r) { // 已经存在包含它的区间
                    int ans = prev->r + 1;
                    printf("%d\n", ans == n + 1 ? -1 : ans); // 输出答案
                } else {
                    printf("%d\n", t); // 不存在包含它的区间，答案是自身
                }
            } else { // 没有找到，不被包含
                printf("%d\n", t);
            }
        }
    }
    return 0;
}