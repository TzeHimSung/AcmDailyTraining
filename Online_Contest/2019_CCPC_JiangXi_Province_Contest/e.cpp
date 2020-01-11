#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct item {
    int t, x;
    item() {}
    item(int _t, int _x) {
        t = _t;
        x = _x;
    }
    bool operator< (const item &b)const {
        return t < b.t;
    }
};
struct segment {
    int l, r;
    segment() {}
    segment(int _l, int _r) {
        l = _l;
        r = _r;
    }
    bool operator<(const segment &b)const {
        if (l != b.l) return l < b.l;
        return r < b.r;
    }
};
item items[1000001];
int len[1000001];
vector<int> buffers[1000001];
int front[1000001];
vector<segment> overflow;
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        int t, x;
        scanf("%d%d", &t, &x);
        items[i] = item(t, x);
    }
    for (int i = 1; i <= m; ++i) scanf("%d", &len[i]);
    sort(items, items + n);
    overflow.clear();
    for (int i = 0; i < n; ++i) {
        buffers[items[i].x].push_back(items[i].t);
        //cout<<buffers[items[i].x].size()<<endl;
        if (buffers[items[i].x].size() > len[items[i].x]) {
            auto t = buffers[items[i].x][front[i]];
            front[i]++;
            //buffers[items[i].x].pop();
            overflow.push_back(segment(t, items[i].t));
        }
    }
    long long ans = 0;
    int last = 0;
    for (auto i : overflow) {
        //cout<<"pp:"<<i.l<<' '<<i.r<<endl;
        if (i.l > last) last = i.l + 1;
        else last++;
        ans += max(0, last - i.r - 1);
    }
    printf("%lld\n", ans);
}