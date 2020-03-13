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

bool check(vector<int> &history) {
    int run = 0, stop = 0, i = 0, size = history.size();
    // 找到下一个跑的日子
    while (!history[i] && i < size) i++;
    for (; i < size; i++) {
        if (history[i]) run++;
        else {
            stop++;
            if (stop == 4) {
                run = stop = 0;
                while (!history[i] && i < size) i++;
            } else run++;
        }
        if (run > 4) return true; // 违章
    }
    return false;
}

int main() {
    vector<int>a{1, 0, 1, 1, 1, 0, 0, 0};
    cout << check(a) << endl;
    return 0;
}