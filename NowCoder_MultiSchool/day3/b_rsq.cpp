#include<cstdio>
#include<cstring>
#include<map>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<string>
using namespace std;
map<int, int> M;
int main() {
    int Sum = 0;
    int n;
    cin >> n;
    string s;
    cin >> s;
    int n0, n1;
    n0 = 0; n1 = 0;
    int ans = 0;
    M[0] = -1;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            n0++;
            Sum--;
        } else {
            n1++;
            Sum++;
        }
        if (M.count(Sum)) {
            M[Sum] = min(M[Sum], i);
        } else {
            M[Sum] = i;
        }
        ans = max(ans, i - M[Sum]);
    }
    cout << ans << " " << min(n0, n1) * 2 << endl;

    return 0;
}