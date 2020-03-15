#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define ff first
#define ss second

const int N = 1 << 18;
const double PI = acos(-1.0);

struct cpx {
    double x, y;
    cpx() {}
    cpx(double _x, double _y)
        : x(_x)
        , y(_y) {
    }
    cpx operator+(const cpx &b) const {
        return cpx(x + b.x, y + b.y);
    }
    cpx operator-(const cpx &b) const {
        return cpx(x - b.x, y - b.y);
    }
    cpx operator*(const cpx &b) const {
        return cpx(x * b.x - y * b.y, x * b.y + y * b.x);
    }
    cpx operator/(const int &b) const {
        return cpx(x / b, y / b);
    }
};

int rev[2 * N + 10];
void getrev(int len) {
    int bit = 0;
    while ((1 << bit) < len)
        bit++;
    for (int i = 0; i < len; i++)
        rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (bit - 1));
}

void fft(cpx x[], int len, int opt) {
    for (int i = 0; i < len; i++)
        if (i < rev[i])
            swap(x[i], x[rev[i]]);
    for (int mid = 1; mid < len; mid <<= 1) {
        cpx tmp(cos(PI / mid), opt * sin(PI / mid));
        for (int i = 0, add = mid << 1; i < len; i += add) {
            cpx base(1, 0);
            for (int j = i; j < i + mid; j++, base = base * tmp) {
                cpx a = x[j], b = base * x[j + mid];
                x[j] = a + b, x[j + mid] = a - b;
            }
        }
    }

    if (opt == -1)
        for (int i = 0; i < len; i++)
            x[i] = x[i] / len;
}

cpx ffta[2 * N + 10], fftb[2 * N + 10];
int solve(int a[], int b[], int lena, int lenb) {
    int len = 1;
    while (len < lena + lenb)
        len <<= 1;
    getrev(len);

    for (int i = 0; i < lena; i++)
        ffta[i] = cpx(a[i], 0);
    for (int i = lena; i < len; i++)
        ffta[i] = cpx(0, 0);
    for (int i = 0; i < lenb; i++)
        fftb[i] = cpx(b[i], 0);
    for (int i = lenb; i < len; i++)
        fftb[i] = cpx(0, 0);

    fft(ffta, len, 1), fft(fftb, len, 1);
    for (int i = 0; i < len; i++)
        ffta[i] = ffta[i] * fftb[i];
    fft(ffta, len, -1);
    return len;
}

char p[200010], t[200010];
ll dam[N * 2 + 10], ans[N];
const char s1[] = { "RNE" }, s2[] = { "ABC" };
int numa[200010], numb[200010], D[10];
int main() {
    int a, b, c, h;
    scanf("%d%d%d%d", &D[0], &D[1], &D[2], &h);
    scanf("%s%s", p + 1, t + 1);
    int n = strlen(p + 1), m = strlen(t + 1);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j <= n; j++)
            numa[j] = numb[j] = 0;
        for (int j = 1; j <= n; j++)
            if (p[j] == s1[i])
                numa[j]++;
        for (int j = 1; j <= m; j++)
            if (t[j] == s2[i])
                numb[n - j + 1]++;
        int len = solve(numa, numb, n + 4, n + 4);
        for (int j = 0; j < len; j++)
            dam[j] += (ll)(ffta[j].x + 0.5) * D[i];
        //for (int j = 0; j < len; j++)
        //    printf("%d %d %lf\n", numa[j], numb[j], ffta[i].x);
    }
    int ansn = 0;
    for (int i = 0; i < 2 * N; i++) {
        ans[i % n] += dam[i];
    }
    for (int i = 0; i < n; i++) {
        if (ans[i] >= h)
            ansn++;
        //printf("%lld ", ans[i]);
    }
    int g = __gcd(ansn, n);
    printf("%d %d\n", ansn / g, n / g);
}