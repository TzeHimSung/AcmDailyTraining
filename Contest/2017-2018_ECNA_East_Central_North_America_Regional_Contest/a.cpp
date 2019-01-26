/* basic header */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <climits>
#include <cmath>
#include <cstdint>
/* STL */
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <array>
#include <iterator>
/* define */
#define ll int64_t
#define dou double
#define pb emplace_back
#define mp make_pair
#define fir first
#define sec second
#define init(a,b) fill(begin(a),end(a),b)
#define sot(a,b) sort(a+1,a+1+b)
#define rep1(i,a,b) for(int i=a;i<=b;i++)
#define rep0(i,a,b) for(int i=a;i<b;i++)
#define repa(i,a) for(auto &i:a)
#define eps 1e-8
#define inf 0x3f3f3f3f
#define lson curr<<1
#define rson curr<<1|1
/* namespace */
using namespace std;
/* header end */

#define x first
#define y second
#define eps 1e-8
#define maxp 30
#define maxn 110

pair<double, double> operator+(pair<double, double> a, pair<double, double> b)
{
    return mp(a.first + b.first, a.second + b.second);
}

pair<double, double> operator-(pair<double, double> a, pair<double, double> b)
{
    return mp(a.first - b.first, a.second - b.second);
}

double operator*(pair<double, double> a, pair<double, double> b)
{
    return a.first * b.second - b.first * a.second;
}

double operator^(pair<double, double> a, pair<double, double> b)
{
    return a.first * b.first + a.second * b.second;
}

double cross(pair<double, double> o, pair<double, double> a, pair<double, double> b)
{
    return (a - o) * (b - o);
}

int cmp(double x)
{
    if (fabs(x) < eps) return 0;
    return x > 0 ? 1 : -1;
}

class Polygon
{
private:
    int i;

public:
    int n;
    pair<double, double> p[maxp];
    pair<double, double>& operator[](int idx)
    {
        return p[idx];
    }
    void input()
    {
        rep0(i, 0, n) cin >> p[i].x >> p[i].y;
        p[n] = p[0];
    }
    double area()
    {
        double s = 0;
        rep0(i, 0, n) s += p[i] * p[i + 1];
        return s / 2;
    }
};

pair<double, int> s[maxn * maxp * 2];
Polygon p[maxn];
double ss, ts;
int n;

double seg(pair<double, double> o, pair<double, double> a, pair<double, double> b)
{
    if (cmp(b.first - a.first) == 0)
        return (o.second - a.second) / (b.second - a.second);
    return (o.first - a.first) / (b.first - a.first);
}

double PolygonUnion()
{
    double ret = 0;
    rep0(i, 0, n)
    for (int ii = 0; ii < p[i].n; ii++)
    {
        int cnt = 0;
        s[cnt++] = mp(0.00, 0);
        s[cnt++] = mp(1.00, 0);
        rep0(j, 0, n)
        if (i != j) for (int jj = 0; jj < p[j].n; jj++)
            {
                int c1 = cmp(cross(p[i][ii], p[i][ii + 1], p[j][jj]));
                int c2 = cmp(cross(p[i][ii], p[i][ii + 1], p[j][jj + 1]));
                if (!c1 && !c2)
                {
                    if (i > j && ((p[i][ii + 1] - p[i][ii]) ^ (p[j][jj + 1] - p[j][jj])) > 0)
                    {
                        s[cnt++] = mp(seg(p[j][jj], p[i][ii], p[i][ii + 1]), 1);
                        s[cnt++] = mp(seg(p[j][jj + 1], p[i][ii], p[i][ii + 1]), -1);
                    }
                }
                else
                {
                    double s1 = cross(p[j][jj], p[j][jj + 1], p[i][ii]);
                    double s2 = cross(p[j][jj], p[j][jj + 1], p[i][ii + 1]);
                    if (c1 >= 0 && c2 < 0)
                        s[cnt++] = mp(s1 / (s1 - s2), 1);
                    else if (c1 < 0 && c2 >= 0) s[cnt++] = mp(s1 / (s1 - s2), -1);
                }
            }
        sort(s, s + cnt);
        double pre = min(max(s[0].x, 0.0), 1.0), now, sum = 0;
        int cov = s[0].y;
        rep0(j, 1, cnt)
        {
            now = min(max(s[j].x, 0.0), 1.0);
            if (!cov) sum += now - pre;
            cov += s[j].y;
            pre = now;
        }
        ret += p[i][ii] * p[i][ii + 1] * sum;
    }
    ret /= 2; return ret;
}

int main()
{
    cin >> n;
    rep0(i, 0, n)
    {
        cin >> p[i].n;
        p[i].input();
        ts = p[i].area();
        if (cmp(ts) < 0)
        {
            reverse(p[i].p, p[i].p + p[i].n);
            p[i][p[i].n] = p[i][0];
            ts = -ts;
        }
        ss += ts;
    }
    printf("%.9f %.9f\n", ss, PolygonUnion());
    return 0;
}