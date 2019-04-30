#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
int n, q, la, lb, lc, p[N], sum[N][27], f[255][255][255];
char s[N], a[N], b[N], c[N];
int find(int v, int pos)
{
    if (pos > n)return 1e9;
    if (sum[n][v] - sum[pos - 1][v] == 0)return 1e9;
    int L = pos, R = n, mid, ret = 1e9;
    while (L <= R)
    {
        mid = L + R >> 1;
        if (sum[mid][v] - sum[pos - 1][v] == 0)L = mid + 1;
        else R = mid - 1, ret = mid;
    }
    return ret;
}
void del1()
{
    for (int i = 0; i <= lb; i++)
        for (int j = 0; j <= lc; j++)
            f[la][i][j] = 1e9;
    la--;
}
void del2()
{
    for (int i = 0; i <= la; i++)
        for (int j = 0; j <= lc; j++)
            f[i][lb][j] = 1e9;
    lb--;
}
void del3()
{
    for (int i = 0; i <= la; i++)
        for (int j = 0; j <= lb; j++)
            f[i][j][lc] = 1e9;
    lc--;
}
void add1()
{
    la++; cin >> a[la];
    p[n + 1] = 1e9;
        for (int i = n; i >= 1; i--)if (s[i] == a[la])p[i] = i; else p[i] = p[i + 1];
    for (int i = 0; i <= lb; i++)
        for (int j = 0; j <= lc; j++)
            if (f[la - 1][i][j] < 1e9)
                f[la][i][j] = p[f[la - 1][i][j] + 1];
            else f[la][i][j] = 1e9;
    for (int i = 0; i <= lb; i++)
        for (int j = 0; j <= lc; j++)
            if (f[la][i][j] < 1e9)
            {
                int pos = i < lb ? find(b[i + 1] - 'a', f[la][i][j] + 1) : 1e9;
                if (pos < 1e9)f[la][i + 1][j] = min(f[la][i + 1][j], pos);
                pos = j < lc ? find(c[j + 1] - 'a', f[la][i][j] + 1) : 1e9;
                if (pos < 1e9)f[la][i][j + 1] = min(f[la][i][j + 1], pos);
            }
}
void add2()
{
    lb++; cin >> b[lb];
    p[n + 1] = 1e9;
        for (int i = n; i >= 1; i--)if (s[i] == b[lb])p[i] = i; else p[i] = p[i + 1];
    for (int i = 0; i <= la; i++)
        for (int j = 0; j <= lc; j++)
            if (f[i][lb - 1][j] < 1e9)
                f[i][lb][j] = p[f[i][lb - 1][j] + 1];
            else f[i][lb][j] = 1e9;
    for (int i = 0; i <= la; i++)
        for (int j = 0; j <= lc; j++)
            if (f[i][lb][j] < 1e9)
            {
                int pos = i < la ? find(a[i + 1] - 'a', f[i][lb][j] + 1) : 1e9;
                if (pos < 1e9)f[i + 1][lb][j] = min(f[i + 1][lb][j], pos);
                pos = j < lc ? find(c[j + 1] - 'a', f[i][lb][j] + 1) : 1e9;
                if (pos < 1e9)f[i][lb][j + 1] = min(f[i][lb][j + 1], pos);
            }
}
void add3()
{
    lc++; cin >> c[lc];
    p[n + 1] = 1e9;
        for (int i = n; i >= 1; i--)if (s[i] == c[lc])p[i] = i; else p[i] = p[i + 1];
    for (int i = 0; i <= la; i++)
        for (int j = 0; j <= lb; j++)
            if (f[i][j][lc - 1] < 1e9)
                f[i][j][lc] = p[f[i][j][lc - 1] + 1];
            else f[i][j][lc] = 1e9;
    for (int i = 0; i <= la; i++)
        for (int j = 0; j <= lb; j++)
            if (f[i][j][lc] < 1e9)
            {
                int pos = i < la ? find(a[i + 1] - 'a', f[i][j][lc] + 1) : 1e9;
                if (pos < 1e9)f[i + 1][j][lc] = min(f[i + 1][j][lc], pos);
                pos = j < lb ? find(b[j + 1] - 'a', f[i][j][lc] + 1) : 1e9;
                if (pos < 1e9)f[i][j + 1][lc] = min(f[i][j + 1][lc], pos);
            }
}
int main()
{
    scanf("%d%d", &n, &q);
    scanf("%s", s + 1);
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < 26; j++)
            sum[i][j] = sum[i - 1][j] + (j == s[i] - 'a');
    for (int i = 0; i <= 250; i++)
        for (int j = 0; j <= 250; j++)
            for (int k = 0; k <= 250; k++)
                f[i][j][k] = 1e9;
    f[0][0][0] = 0;
    while (q--)
    {
        char ch; int x;
        cin >> ch >> x;
        if (ch == '+')
        {
            if (x == 1)add1();
            else if (x == 2)add2();
            else add3();
        }
        else if (x == 1)del1();
        else if (x == 2)del2();
        else del3();
        if (f[la][lb][lc] == 1e9)puts("NO");
        else puts("YES");
    }
}