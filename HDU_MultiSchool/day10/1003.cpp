/* Codeforces Contest 2019_mutc_10
 * Problem C
 * Au: SJoshua
 */
#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

const double eps = 1e-9;

int main(void) {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        vector <double> p(n);
        for (int i = 0; i < n; i++) {
            scanf("%lf", &p[i]);
        }
        sort(p.begin(), p.end(), greater <double> ());
        double a = 1.0, b = 0.0, c = 0.0;
        for (int i = 0; i < n; i++) {
            double nxt = b * (1 - p[i]) + a * p[i];
            if (nxt - b > eps) {
                a = a * (1 - p[i]);
                b = nxt;
            }
        }
        printf("%.9f\n", b);
    }
    return 0;
}