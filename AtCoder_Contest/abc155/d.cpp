/* basic header */
#include <bits/stdc++.h>
/* define */
#define ll long long
#define pb emplace_back
#define mp make_pair
#define eps 1e-8
#define lson (curpos<<1)
#define rson (curpos<<1|1)
/* namespace */
using namespace std;
/* header end */

const int maxn = 2e5 + 10;
int n, k, p = 0, q = 0, numZ = 0;
ll a[maxn], b[maxn];

bool check1(ll num) {
    int cnt = 0;
    for (int i = 0; i < p; i++) cnt += q - (upper_bound(b, b + q, num / a[i]) - b);
    return cnt < k + 1;
}

bool check2(ll *a, int len, ll num) {
    int cnt = 0;
    for (int i = 0; i < len; i++) cnt += len - (upper_bound(a, a + len, num / a[i]) - a);
    return cnt < k + 1;
}

bool check3(ll *a, int len, ll num) {
    int cnt = 0;
    for (int i = 0; i < len; i++) cnt += len - (upper_bound(a, a + len, num / a[i]) - a);
    return cnt < k + 2;
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (x > 0) a[p++] = x;
        else if (x < 0) b[q++] = x;
        else numZ++;
    }
    sort(a, a + p);
    sort(b, b + q);
    if (p && q && p * q >= k) {
        ll l = a[p - 1] * b[0], r = a[0] * b[q - 1];
        while (l <= r) {
            ll mid = (l + r) / 2;
            if (check1(mid)) l = mid + 1;
            else r = mid - 1;
        }
        cout << r << endl;
        return 0;
    }
    k -= p * q;
    numZ = numZ * (n - numZ) + numZ * (numZ - 1) / 2;
    if (numZ >= k) {
        cout << "0" << endl;
        return 0;
    }
    k -= numZ;
    int odd = k & 1 ? 1 : 0, pos1 = -1, pos2 = -1, pos3 = -1, pos4 = -1;
    if (p > 1 && q > 1) k /= 2;
    if (p > 1) {
        ll l = a[0] * a[1], r = a[p - 1] * a[p - 1];
        while (l <= r) {
            ll mid = (l + r) / 2;
            if (check2(a, p, mid)) l = mid + 1;
            else r = mid - 1;
        }
        pos1 = l;
        if (q > 1) { // k+1 da
            l = a[0] * a[0], r = a[p - 1] * a[p - 1];
            while (l <= r) {
                ll mid = (l + r) / 2;
                if (check3(a, p, mid)) l = mid + 1;
                else r = mid - 1;
            }
            pos2 = l;
        } else {
            cout << pos1 << endl;
            return 0;
        }
    }
    if (q > 1) {
        ll l = b[q - 1] * b[q - 1], r = b[0] * b[0];
        while (l <= r) {
            ll mid = (l + r) / 2;
            if (check2(b, q, mid)) l = mid + 1;
            else r = mid - 1;
        }
        pos3 = l;
        if (p > 1) {
            l = b[q - 1] * b[q - 1], r = b[0] * b[0];
            while (l <= r) {
                ll mid = (l + r) / 2;
                if (check3(b, q, mid)) l = mid + 1;
                else r = mid - 1;
            }
            pos4 = l;
        } else {
            cout << pos3 << endl;
            return 0;
        }
    }
    if (odd) {
        if (pos3 == -1) cout << pos4 << endl;
        else if (pos4 == -1) cout << pos3 << endl;
        else cout << min(pos3, pos4) << endl;
    } else {
        if (pos1 == -1) cout << pos2 << endl;
        else if (pos2 == -1) cout << pos1 << endl;
        else cout << max(pos1, pos2) << endl;
    }
    return 0;
}
/*
10 40
5 4 3 2 -1 0 0 0 0 0
4 fushu
5*5/2+
 */