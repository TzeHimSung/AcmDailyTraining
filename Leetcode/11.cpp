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

int maxArea(vector<int> &height) {
    int i = 0, j = (int)height.size() - 1, ans = 0;
    while (i < j) {
        ans = max(ans, (j - i) * min(height[i], height[j]));
        height[i] < height[j] ? i++ : j--;
    }
    return ans;
}

int main() {
    vector<int>test{1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << maxArea(test) << endl;
    return 0;
}