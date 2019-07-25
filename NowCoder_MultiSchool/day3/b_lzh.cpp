#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <queue>
#include <map>
#include <set>
#include <stack>
using namespace std;
#define ll long long
#define ull unsigned long long
#define up(i, a, b) for (int i = (a); i <= (b); i++)
#define down(i, a, b) for (int i = (a); i >= (b); i--)
#define mem(x, y) memset(x, (y), sizeof x)
#define ff first
#define ss second
#define mp(x, y) make_pair(x, y)
#define pb(x) push_back(x)
#define sc(a) scanf("%d", &a)
#define scl(a) scanf("%lld", &a)
#define scs(a) scanf("%s", a)
#define pr(a, b) printf("%d%c", a, b)
#define prl(a, b) printf("%lld%c", a, b)
#define PQ priority_queue
#define ld long double
#define all(v) v.begin(), v.end()
#define IOS ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)

typedef pair<int, int> pii;
typedef map<int, int> mii;
typedef vector<int> V;

// const int maxn = 1e5 + 10;
const int maxn = 10;
char s[maxn];
int a0[maxn], a1[maxn], n;
bool check(int x) {
    up(i, 2 * x, n)
    if (a0[i] - a0[i - 2 * x] == a1[i] - a1[i - 2 * x])return true;
    return false;
}
int main() {
    sc(n); scs(s + 1);
    up(i, 1, n) {
        a0[i] = a0[i - 1], a1[i] = a1[i - 1];
        if (s[i] == '0')a0[i]++;
        else a1[i]++;
    }
    int ansb = 2 * min(a0[n], a1[n]), ansa = 0;
    int l = 1, r = n / 2;
    while (l <= r) {
        int mid = l + r >> 1;
        if (check(mid))l = mid + 1;
        else r = mid - 1;
    }
    ansa = 2 * r;
    pr(ansa, ' '), pr(ansb, '\n');
}