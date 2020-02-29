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

string solve(int x) {
    int bit = 0;
    string s = "";
    if (!x) return "0";
    do {
        if (x & 1) {
            s = (bit == 1 ? "2" : "2(" + solve(bit) + ")") + (s == "" ? "" : "+") + s;
        }
    } while (bit++, x >>= 1);
    return s;
}

int main() {
    int a; scanf("%d", &a);
    printf("%s\n", solve(a).c_str());
    return 0;
}