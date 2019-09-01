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

vector<pair<int, int>>v1, v2, v3, v4;
// v1: up left
// v2: up right
// v3: down left
// v4: down right

struct Vector {
    int x, y;
}

int main() {
    int n; scanf("%d", &n);
    double ans = 0.0, currX = 0, currY = 0;
    for (int i = 1; i <= n; i++) {
        int x, y; scanf("%d%d", &x, &y);
        if (x < 0) {
            if (y > 0) v1.pb(mp(x, y));
            else if (y == 0) v1.pb(mp(x, y)), v3.pb(mp(x, y));
            else v3.pb(mp(x, y));
        } else if (x == 0) {
            if (y > 0) v1.pb(mp(x, y)), v2.pb(mp(x, y));
            else v3.pb(mp(x, y)), v4.pb(mp(x, y));
        } else {
            if (y > 0) v2.pb(mp(x, y));
            else if (y == 0) v2.pb(mp(x, y)), v4.pb(mp(x, y));
            else v4.pb(mp(x, y));
        }
    }
    for (auto i : v1) currX += i.first, currY += i.second;
    ans = max(ans, sqrt(pow(currX, 2) + pow(currY, 2)));

    //------------------------------------------------------
    currX = 0, currY = 0;
    for (auto i : v2) currX += i.first, currY += i.second;
    ans = max(ans, sqrt(pow(currX, 2) + pow(currY, 2)));

    //------------------------------------------------------
    currX = 0, currY = 0;
    for (auto i : v3) currX += i.first, currY += i.second;
    ans = max(ans, sqrt(pow(currX, 2) + pow(currY, 2)));

    //------------------------------------------------------
    currX = 0, currY = 0;
    for (auto i : v4) currX += i.first, currY += i.second;
    ans = max(ans, sqrt(pow(currX, 2) + pow(currY, 2)));

    printf("%.55f\n", ans);
    return 0;
}