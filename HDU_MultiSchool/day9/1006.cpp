/* Codeforces Contest 2019_mutc_09
 * Problem F
 * Au: SJoshua
 */
#include <cstdio>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

bool sol[10][5][2][21];

void search(void) {
    vector <int> c1;
    for (int p10 = 0; p10 <= 9; p10++) {
        auto c2 = c1;
        for (int p20 = 0; p20 <= 4; p20++) {
            auto c3 = c2;
            for (int p50 = 0; p50 <= 1; p50++) {
                for (unsigned int i = 0; i < 1 << c3.size(); i++) {
                    int sum = 0;
                    for (int j = 0; j < c3.size(); j++) {
                        sum += c3[j] * ((i >> j) & 1);
                    }
                    if (sum <= 20) {
                        sol[p10][p20][p50][sum] = true;
                    }
                }
                c3.push_back(5);
            }
            c2.push_back(2);
        }
        c1.push_back(1);
    }
}

int solve(int n) {
    int dollar = 0;
    vector <bool> rec(10), ext(10), top(10); // rec: 100以下 ext: 100以上
    int maxn = 0;
    vector <int> raw(n);
    bool fake = false;
    for (int i = 0; i < n; i++) {
        cin >> raw[i];
        int bit = raw[i] / 100;
        if (bit > maxn) {
            maxn = bit;
            for (int i = 0; i < 10; i++) {
                top[i] = false;
            }
        }
        if (bit == maxn) {
            top[raw[i] % 100 / 10] = true;
        }
        dollar = max(dollar, bit);
        if (raw[i] >= 100) {
            ext[raw[i] % 100 / 10] = true;
        } else {
            rec[raw[i] % 100 / 10] = true;
        }
        if (raw[i] % 10) {
            fake = true;
        }
    }
    if (fake) {
        return -1;
    }
    int ans = 99999999;
    int a, b, c, d;
    for (int i = 0; i <= 9; i++) {
        for (int j = 0; j <= 4; j++) {
            for (int k = 0; k <= 1; k++) {
                bool flag = true, flag2 = true;
                for (int p = 0; p <= 9; p++) {
                    if (rec[p]) {
                        // 7 20 40 50 60 70 90 110
                        // 100+的是否都能直接拿出来？
                        if (!sol[i][j][k][p]) {
                            flag = false;
                            break;
                        }
                    }
                    if (ext[p]) {
                        if (!(sol[i][j][k][p] || sol[i][j][k][p + 10])) {
                            flag = false;
                            break;
                        }
                    }
                    if (top[p]) {
                        if (!sol[i][j][k][p + 10]) {
                            flag2 = false;
                        }
                    }
                }
                if (flag) {
                    int cur = i + j + k + dollar;
                    if (dollar && flag2) {
                        cur--;
                    }
                    if (cur < ans) {
                        ans = cur;
                        a = i, b = j, c = k;
                        d = dollar;
                        if (dollar && flag2) {
                            d--;
                        }
                    }
                }
            }
        }
    }
    // cout << a << b << c << d << endl;
    return ans;
}

int main(void) {
    int T;
    cin >> T;
    search();
    while (T--) {
        int n;
        cin >> n;
        cout << solve(n) << endl;
    }
    return 0;
}

