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

const int MAXN = 100;
int a[MAXN], b[MAXN];

int main() {
    for (int i = 0; i < MAXN; i++) {
        a[i] = i, b[i] = i / 10;
    }

    function<int(int *, int)> binary_search_noDoublicate = [&](int *a, int target)->int{
        int l = 0, r = MAXN;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (a[mid] == target) return mid;
            else if (a[mid] < target) l = mid + 1;
            else r = mid - 1;
        }
        return l;
    };

    function<int(int *, int)> binary_search_lower_bound = [&](int *a, int target)->int{
        int l = 0, r = MAXN - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (a[mid] < target) l = mid + 1;
            else r = mid - 1;
        }
        return l;
    };

    function<int(int *, int)> binary_search_upper_bound = [&](int *a, int target)->int{
        int l = 0, r = MAXN - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (a[mid] <= target) l = mid + 1;
            else r = mid - 1;
        }
        return r;
    };

    cout << binary_search_noDoublicate(b, 8) << endl;
    cout << binary_search_lower_bound(b, 8) << endl;
    cout << binary_search_upper_bound(b, 8) << endl;

    return 0;
}