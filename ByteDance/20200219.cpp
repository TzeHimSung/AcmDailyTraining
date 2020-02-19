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

const int maxn = 1e6 + 10;
int a[maxn << 1], n, k;
vector<int>ans;
queue<int>q;

int main() {
    // init
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n + k - 1; i++) scanf("%1d", &a[i]);
    while (q.size()) q.pop();

    // solve
    int currXor = 0;
    for (int i = 1; i <= n; i++) {
        if ((int)q.size() == k) {
            currXor ^= q.front();
            q.pop();
        }
        int newVal = a[i] ^ currXor;
        currXor ^= newVal;
        ans.push_back(newVal);
        q.push(newVal);
    }

    for (auto i : ans) printf("%d", i);
    puts("");
    return 0;
}

/*
7 4
1110100110

1001010
 1001010
  1001010
   1001010
1110100110

 */