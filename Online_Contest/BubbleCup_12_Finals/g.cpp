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

int n, m;
struct Node {
    ll val, pos;
    Node() {}
    Node(int _val, int _pos): val(_val), pos(_pos) {}

    bool operator<(const Node &rhs)const {
        return val != rhs.val ? val > rhs.val : pos < rhs.pos;
    }
};

int main() {
    scanf("%d%d", &n, &m);
    // int a[n + 1][m + 1], b[n + 1][m + 1], c[n + 1][m + 1];
    int a[n + 1][m + 1];
    Node row[n + 1], col[m + 1], trow[n + 1], tcol[m + 1];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            scanf("%d", &a[i][j]);
    for (int i = 1; i <= n; i++) {
        row[i].val = 0;
        row[i].pos = i;
        for (int j = 1; j <= m; j++) row[i].val += a[i][j];
        trow[i] = row[i];
    }
    for (int j = 1; j <= m; j++) {
        col[j].val = 0;
        col[j].pos = j;
        for (int i = 1; i <= n; i++) col[j].val += a[i][j];
        tcol[j] = col[j];
    }
    sot(trow, n); sot(tcol, m);
    // for (int i = 1; i <= n; i++)
    //     for (int j = 1; j <= m; j++) {
    //         b[i][j] = row[i].val + col[j].val - a[i][j];
    //         c[i][j] = row[i].val + col[j].val - 2 * a[i][j];
    //     }
    if (n == 1) {
        printf("%lld\n", row[1].val);
        return 0;
    }
    if (m == 1) {
        printf("%lld\n", col[1].val);
        return 0;
    }
    ll ans1 = 0, ans2 = 0, ans3 = 0;

// #define DEBUG
#ifdef DEBUG
    cout << "The result of row is: ";
    for (int i = 1; i <= n; i++) cout << row[i].val << " ";
    puts("");

    cout << "The result of col is: ";
    for (int i = 1; i <= m; i++) cout << col[i].val << " ";
    puts("");
#endif // DEBUG    

    if (n >= 3) {
        ans1 = row[trow[1].pos].val + row[trow[2].pos].val + row[trow[3].pos].val + col[tcol[1].pos].val
               - a[trow[1].pos][tcol[1].pos] - a[trow[2].pos][tcol[1].pos] - a[trow[3].pos][tcol[1].pos];
    }
    if (n >= 2 && m >= 2) {
        ans2 = row[trow[1].pos].val + row[trow[2].pos].val + col[tcol[1].pos].val + col[tcol[2].pos].val
               - a[trow[1].pos][tcol[1].pos] - a[trow[1].pos][tcol[2].pos] - a[trow[2].pos][tcol[1].pos] - a[trow[2].pos][tcol[2].pos];
    }
    if (m >= 3) {
        ans3 = row[trow[1].pos].val + col[tcol[1].pos].val + col[tcol[2].pos].val + col[tcol[3].pos].val
               - a[trow[1].pos][tcol[1].pos] - a[trow[1].pos][tcol[2].pos] - a[trow[1].pos][tcol[3].pos];
    }

#ifdef DEBUG
    cout << "The ans1 is: " << ans1 << endl;
    cout << "The ans2 is: " << ans2 << endl;
    cout << "The ans3 is: " << ans3 << endl;
#endif // DEBUG
    printf("%lld\n", max(ans1, max(ans2, ans3)));
    return 0;
}