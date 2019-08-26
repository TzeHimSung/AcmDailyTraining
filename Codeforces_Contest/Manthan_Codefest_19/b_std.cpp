#include <bits/stdc++.h>
#define int int64_t
using namespace std;
int n;

bool judge(vector<int> &v, int mid) {
    unordered_map<int, int> m;
    unordered_set<int> s; // counter > 1
    for (int i = 0; i < n; ++i) {
        m[v[i]]++; // counter
        if (m[v[i]] > 1) s.emplace(v[i]);
    }
    for (int i = 0; i < mid; ++i) { // pick all from [0,mid)
        m[v[i]]--;
        if (m[v[i]] < 2) s.erase(v[i]);
    }
    if (s.empty()) return true; // all were picked
    int beg = 0, end = mid;
    while (end < n) {
        m[v[beg]]++;
        if (m[v[beg]] > 1) s.emplace(v[beg]);
        m[v[end]]--;
        if (m[v[end]] < 2) s.erase(v[end]);
        if (s.empty()) return true;
        end++;
        beg++;
    }
    return false;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    vector<int> v(n);
    for (int &i : v) cin >> i;
    int lo = 0, hi = n;
    while (lo < hi) { // 二分数量
        int mid = (lo + hi) / 2;
        if (judge(v, mid)) hi = mid - 1;
        else lo = mid + 1;
    }
    if (lo > 0 and judge(v, lo - 1)) cout << lo - 1;
    else if (judge(v, lo)) cout << lo;
    else cout << max(0ll, lo + 1);
    return 0;
}
