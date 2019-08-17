/* Nowcoder Contest 890
 * Problem B
 * Au: SJoshua
 */
#include <cassert>
#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

const string A("COFFEE"), B("CHICKEN");

vector <long long int> len(70);

char solve(int index, long long int pos) {
    // cout << index << "; " << pos << endl;
    assert(1 <= index && 1 <= pos);
    if (index == 1) {
        if (pos <= 6) {
            return A[pos - 1];
        } else {
            return ' ';
        }
    } else if (index == 2) {
        if (pos <= 7) {
            return B[pos - 1];
        } else {
            return ' ';
        }
    }
    if (pos <= len[index - 2]) {
        return solve(index - 2, pos);
    } else {
        return solve(index - 1, pos - len[index - 2]);
    }
}

int main(void) {
    int T;
    cin >> T;
    len[1] = 6;
    len[2] = 7;
    for (int i = 3; i <= 69; i++) {
        len[i] = len[i - 1] + len[i - 2];
    }
    while (T--) {
        int n;
        long long int k;
        cin >> n >> k;
        n = min(n, 69);
        for (long long int pos = k; pos < k + 10; pos++) {
            if (pos <= len[n]) {
                cout << solve(n, pos);
            }
        }
        cout << endl;
    }
    return 0;
}