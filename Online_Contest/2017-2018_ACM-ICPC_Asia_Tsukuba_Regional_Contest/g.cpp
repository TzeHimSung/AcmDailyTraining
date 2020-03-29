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

const double PI = acos(-1.0);

int main() {
    function<int()> solve = []()->int{
        char s[10];
        double d, l;
        scanf("%s%lf%lf", s, &d, &l);
        double alpha = d * PI / 180.0;
        if (s[0] == 'D') alpha = 2.0 * PI - alpha;
        else if (s[0] == 'B') alpha = PI * 5.0 / 3.0 - alpha;
        else alpha = PI * 4.0 / 3.0 - alpha;

        // printf("%f\n",alpha);
        double x = l * cos(alpha), y = l * sin(alpha);
        while (y < -sqrt(3.0)) x += 1, y += sqrt(3.0);
        x += 1, y += sqrt(3.0);
        double yy = y * 2 / sqrt(3.0), xx = x - yy / 2.0;
        while (xx < 0) xx += 2;
        while (xx > 2) xx -= 2;
        // printf("%f %f\n",xx, yy);

        if (xx < 1 && yy < 1) return (xx + yy < 1) ? 2 : 1;
        if (xx > 1 && xx < 2 && yy < 1) return (xx + yy - 1 < 1) ? 3 : 4;
        if (xx < 1 && yy > 1 && yy < 2) return (xx + yy - 1 < 1) ? 4 : 3;
        if (xx > 1 && yy > 1 && yy < 2) return (xx + yy - 2 < 1) ? 1 : 2;
        return 0;
    };

    int s1 = solve(), s2 = solve();
    printf("%s\n", s1 == s2 ? "YES" : "NO");
    return 0;
}