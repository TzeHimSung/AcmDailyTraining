#include <bits/stdc++.h>
#define pii pair<double,double>
#define ll long long

using namespace std;

const int maxn = 1e3 + 10;
const double eps = 1e-8;
double dp[maxn][2];
pii segment[maxn][2];
int n;

int getSign(double val) {
    return val < -eps ? -1 : val > eps;
}

double getDis(pii &x, pii &y) {
    return sqrt((x.first - y.first) * (x.first - y.first) + (x.second - y.second) * (x.second - y.second));
}

pii update(pii &x, pii &y, double val) {
    double aa = x.first - y.first, bb = x.second - y.second;
    return make_pair(x.first + (val - x.second) * aa / bb, val);
}

int checkLeft(pii p, pii a, pii b) {
    double x1 = a.first - p.first, y1 = a.second - p.second;
    double x2 = b.first - p.first, y2 = b.second - p.second;
    return getSign(x1 * y2 - x2 * y1) > 0;
}

int checkRight(pii p, pii a, pii b) {
    double x1 = a.first - p.first, y1 = a.second - p.second;
    double x2 = b.first - p.first, y2 = b.second - p.second;
    return getSign(x1 * y2 - x2 * y1) >= 0;
}

int main() {
    while (scanf("%d", &n) == 1 && n) {
        scanf("%lf%lf", &segment[0][0].first, &segment[0][0].second);
        for (int i = 1; i <= n; i++) {
            scanf("%lf%lf%lf", &segment[i][0].second, &segment[i][0].first, &segment[i][1].first);
            segment[i][1].second = segment[i][0].second;
        }
        dp[n][0] = dp[n][1] = 0;
        for (int i = n - 1; i >= 0; i--) {
            for (int k = 0; k < 2; k++) {
                dp[i][k] = INT_MAX;
                pair<pii, pii> currLine = make_pair(segment[i + 1][0], segment[i + 1][1]);
                pii pt = segment[i][k];
                int j;
                for (j = i + 1; j <= n; j++) {
                    if (checkLeft(pt, segment[j][1], currLine.first) || checkLeft(pt, currLine.second, segment[j][0]))
                        break;
                    if (checkRight(pt, currLine.first, segment[j][0])) {
                        currLine.first = segment[j][0];
                        dp[i][k] = min(dp[i][k], getDis(pt, currLine.first) + dp[j][0]);
                    }
                    if (checkRight(pt, segment[j][1], currLine.second)) {
                        currLine.second = segment[j][1];
                        dp[i][k] = min(dp[i][k], getDis(pt, currLine.second) + dp[j][1]);
                    }
                }
                if (j > n) {
                    double curr = segment[n][0].second;
                    currLine.first = update(pt, currLine.first, curr), currLine.second = update(pt, currLine.second, curr);
                    if (pt.first < currLine.first.first) dp[i][k] = min(dp[i][k], getDis(pt, currLine.first));
                    else if (pt.first > currLine.second.first) dp[i][k] = min(dp[i][k], getDis(pt, currLine.second));
                    else dp[i][k] = min(dp[i][k], pt.second - curr);
                }
                if (!i) break;
            }
        }
        printf("%.11f\n", dp[0][0]);
    }
    return 0;
}
