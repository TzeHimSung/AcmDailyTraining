/* Nowcoder Contest 887
 * Problem D
 * Au: SJoshua
 */
#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
    int n;
    string p;
    cin >> n >> p;
    if (p.length() > n) {
        cout << "T_T" << endl;
        return 0;
    }
    cout << p;
    for (int i = p.length(); i < n; i++) {
        cout << 0;
    }
    cout << endl;
    return 0;
}