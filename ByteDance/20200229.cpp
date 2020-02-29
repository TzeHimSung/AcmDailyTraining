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

string s;
int remain;
vector<int>money;
map<int, int>ans;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ans.clear(), money.clear();
    cin >> s >> remain;
    int tmp = 0;
    for (auto i : s) {
        if ('0' <= i && i <= '9') tmp = tmp * 10 + i - '0';
        else if (i != '[') {
            money.push_back(tmp);
            tmp = 0;
        }
    }
    sort(money.begin(), money.end());
    for (int i = (int)money.size() - 1; i >= 0 && remain; i--) {
        int num = remain / money[i];
        if (!num) continue;
        ans[money[i]] = num;
        remain -= num * money[i];
    }
    // 实在找不出这么多钱，题目也没有说，隐藏坑点？
    if (remain) return puts("No solution!"), 0;
    int printed = 0;
    cout << "[";
    for (auto i : ans) {
        while (i.second--) {
            if (!printed) {
                printed = 1;
                cout << i.first;
            } else {
                cout << "," << i.first;
            }
        }
    }
    cout << "]" << endl;
    return 0;
}