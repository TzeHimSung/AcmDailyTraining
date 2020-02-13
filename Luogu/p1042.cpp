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

const int maxn = 1e5 + 10;
int r[maxn], winCnt, lostCnt;

int main() {
    char s;
    for (int i = 1; cin >> s && s != 'E'; i++) {
        if (s == 'W') r[i] = 1;
        else r[i] = 2;
    }
    for (int i = 1; 1; i++) {
        if (r[i] == 1) winCnt++;
        else if (r[i] == 2) lostCnt++;
        else if (!r[i]) {
            cout << winCnt << ":" << lostCnt << endl << endl;
            break;
        }
        if (winCnt - lostCnt >= 2 || lostCnt - winCnt >= 2)
            if (winCnt >= 11 || lostCnt >= 11) {
                cout << winCnt << ":" << lostCnt << endl;
                winCnt = 0, lostCnt = 0;
            }
    }
    winCnt = 0, lostCnt = 0;
    for (int i = 1;; i++) {
        if (r[i] == 1) winCnt++;
        else if (r[i] == 2) lostCnt++;
        else if (!r[i]) {
            cout << winCnt << ":" << lostCnt;
            break;
        }
        if (winCnt - lostCnt >= 2 || lostCnt - winCnt >= 2)
            if (winCnt >= 21 || lostCnt >= 21) {
                cout << winCnt << ":" << lostCnt << endl;
                winCnt = 0, lostCnt = 0;
            }
    }
    return 0;
}