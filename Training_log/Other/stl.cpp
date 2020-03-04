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

vector<int>a, b;

int main() {
    a.push_back(0);
    a.push_back(1);
    a.push_back(1);
    b.push_back(1);
    cout << (a < b) << endl;
    return 0;
}