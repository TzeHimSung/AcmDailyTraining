#include<bits/stdc++.h>
#define sqr(x) (x)*(x)
const double pi = acos(-1.0);
using namespace std;
namespace poly
{
struct point
{
    double x, y;
    point(double _x = 0, double _y = 0): x(_x), y(_y) {};
    bool operator <(const point& b) const
    {
        return (y < b.y || (y == b.y && x < b.x));
    }
};
double dist(const point& a, const point& b)
{
    return sqrt(sqr(a.x - b.x) + sqr(a.y - b.y));
}
double cross(const point& a, const point& b, const point& c)
{
    return (a.x - c.x) * (b.y - c.y) - (b.x - c.x) * (a.y - c.y);
}
int graham(point pt[], int n, point res[])
{
    sort(pt, pt + n);
    if (n == 0) return 0; res[0] = pt[0];
    if (n == 1) return 1; res[1] = pt[1];
    if (n == 2) return 2; res[2] = pt[2];
    int top = 1;
    for (int i = 2; i < n; i++)
    {
        while (top && cross(pt[i], res[top], res[top - 1]) >= 0) --top;
        res[++top] = pt[i];
    }
    int len = top; res[++top] = pt[n - 2];
    for (int i = n - 3; i >= 0; i--)
    {
        while (top != len && cross(pt[i], res[top], res[top - 1]) >= 0) --top;
        res[++top] = pt[i];
    }
    return top;
}
};
poly::point pt[2000050], res[2000050];
int main()
{
    int n, cnt = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        double x, y, r;
        cin >> x >> y >> r;
        r += 10;
        //cout<<x<<" "<<y<<" "<<r<<endl;
        for (int j = 0; j < 10000; j++)
        {
            pt[cnt++] = poly::point(x + r * cos(2.0 * pi * (double(j) / 10000.0)), y + r * sin(2.0 * pi * (double(j) / 10000.0)));
        }
    }
    //cout<<cnt<<endl;
    //for (int i=0;i<cnt;i++) cout<<pt[i].x<<" "<<pt[i].y<<endl;
    cnt = poly::graham(pt, cnt, res);
    //cout<<cnt<<endl;
    //for (int i=0;i<cnt;i++) cout<<res[i].x<<" "<<res[i].y<<endl;
    double len = 0;
    res[cnt] = res[0];
    for (int i = 1; i <= cnt; i++) len += poly::dist(res[i - 1], res[i]);
    printf("%.6lf\n", len);
}