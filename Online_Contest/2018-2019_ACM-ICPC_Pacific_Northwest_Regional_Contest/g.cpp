#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn = 200000;

double cal(double x, double y, double x1, double y1)
{
    double a = (x1 - x);
    double b = (y1 - y);
    return sqrt(a * a + b * b);
}

int main()
{
    double x, y, x1, y1, x2, y2;
    cin >> x >> y >> x1 >> y1 >> x2 >> y2;
    double ans = 1e9;
    if (x1 <= x2)
    {
        if (x1 <= x && x <= x2)
        {
            ans = min(abs(y1 - y), abs(y2 - y));
        }
    }
    else
    {
        if (x2 <= x && x <= x1)
        {
            ans = min(abs(y1 - y), abs(y2 - y));
        }
    }
    if (y1 <= y2)
    {
        if (y1 <= y && y <= y2)
        {
            ans = min(abs(x1 - x), abs(x2 - x));
        }
    }
    else
    {
        if (y2 <= y && y <= y1)
        {
            ans = min(abs(x1 - x), abs(x2 - x));
        }
    }
    ans = min(ans, cal(x, y, x1, y1));
    ans = min(ans, cal(x, y, x1, y2));
    ans = min(ans, cal(x, y, x2, y1));
    ans = min(ans, cal(x, y, x2, y2));
    printf("%.3lf\n", ans);
    return 0;
}