/* basic header */
#include <bits/stdc++.h>
/* define */
#define ll long long
#define dou double
#define pb emplace_back
#define mp make_pair
#define sot(a,b) sort(a+1,a+1+b)
#define rep1(i,a,b) for(int i=a;i<=b;++i)
#define rep0(i,a,b) for(int i=a;i<b;++i)
#define eps 1e-8
#define int_inf 0x3f3f3f3f
#define ll_inf 0x7f7f7f7f7f7f7f7f
#define lson (curpos<<1)
#define rson (curpos<<1|1)
/* namespace */
using namespace std;
/* header end */

const int px[] = {-1, 0, 1, 0}, py[] = {0, 1, 0, -1};
struct Map {
    int a[4][4], x, y;
    string hashs;
    bool operator<(const Map &rhs) const {
        if (x != rhs.x) return x < rhs.x;
        else return y < rhs.y;
    }
    bool operator==(const Map &rhs)const {
        if (x != rhs.x || y != rhs.y) return false;
        if (hashs != rhs.hashs) return false;
        return true;
    }
};
set<string>ss, used;
map<string, Map>mm;

void solve() {
    used.clear();
    Map fir; string tmp = "";
    for (int i = 0; i < 16; i++) {
        fir.a[i / 4][i % 4] = (i + 1) % 16;
        if (fir.a[i / 4][i % 4] < 10)
            tmp = tmp + '0' + (char)(fir.a[i / 4][i % 4] + 48);
        else {
            int aa = fir.a[i / 4][i % 4] / 10, bb = fir.a[i / 4][i % 4] % 10;
            tmp = tmp + (char)(aa + 48) + (char)(bb + 48);
        }
    }
    fir.x = 3, fir.y = 3; fir.hashs = tmp;
    ss.insert(tmp); mm[tmp] = fir;
    int step = 300;
    while (step) {
        Map curr;
        for (auto i : ss)
            if (!used.count(i)) {
                curr = mm[i]; used.insert(i); break;
            }
        int cx = curr.x, cy = curr.y;
        for (int i = 0; i < 4; i++) {
            int nx = cx + px[i], ny = cy + py[i];
            if (nx < 0 || nx >= 4 || ny < 0 || ny >= 4) continue;
            Map newMap = curr; swap(newMap.a[cx][cy], newMap.a[nx][ny]);
            newMap.x = nx, newMap.y = ny;
            string str = "";
            for (int i = 0; i < 16; i++) {
                if (newMap.a[i / 4][i % 4] < 10)
                    str = str + '0' + (char)(newMap.a[i / 4][i % 4] + 48);
                else {
                    int aa = newMap.a[i / 4][i % 4] / 10, bb = newMap.a[i / 4][i % 4] % 10;
                    str = str + (char)(aa + 48) + (char)(bb + 48);
                }
            }
            newMap.hashs = str;
            ss.insert(str);
            mm[str] = newMap;
            step--;
        }
    }
}

int main() {
    solve();
    printf("%d\n", (int)ss.size());
    printf("%d\n", (int)mm.size());
    int t; scanf("%d", &t);
    while (t--) {
        Map a; string cur = "";
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++) {
                int x; scanf("%d", &x);
                if (x < 10) cur = cur + '0' + (char)(x + 48);
                else {
                    int aa = x / 10, bb = x % 10;
                    cur = cur + (char)(aa + 48) + (char)(bb + 48);
                }
            }
        if (ss.count(cur)) puts("YES");
        else puts("NO");
    }
    return 0;
}