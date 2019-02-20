/* basic header */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <cmath>
#include <cstdint>
#include <climits>
#include <float.h>
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
#define ll long long
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
#define int_inf 0x3f3f3f3f
#define ll_int 0x7f7f7f7f7f7f7f7f
#define lson curPos<<1
#define rson curPos<<1|1
/* namespace */
using namespace std;
/* header end */

const int maxn = 1e5 + 10;
int cnt[maxn], n, x;

int main()
{
    cin >> n;
    int prak = n;
    rep1(i, 1, n * n)
    {
        cin >> x;
        cnt[x]++; //count number of digit
    }
    int a[n][n];
    int j, k = 1;
    int r = 0, c = 0;
    for (; k <= (n / 2) * (n / 2); k++)
    {
        for (j = 1; j <= 1000; j++)
        {
            if ( cnt[j] > 3)
                break;
        }
        if (j > 1000)
        {
            cout << "NO" << endl;
            return 0;
        }
        a[r][c] = j;
        a[r][n - 1 - c] = j;
        a[n - 1 - r][c] = j;
        a[n - 1 - r][n - 1 - c] = j;
        cnt[j] = cnt[j] - 4;
        c++;
        if (c == (n / 2))
        {
            c = 0;
            r++;
        }
    }
    if (n & 1)
    {
        for (int i = 0; i < (n / 2); i++)
        {
            for (j = 1; j <= 1000; j++)
            {
                if ( cnt[j] > 1)
                    break;
            }
            if (j > 1000)
            {
                cout << "NO" << endl;
                return 0;
            }
            a[n / 2][i] = j;
            a[n / 2][n - 1 - i] = j;
            cnt[j] -= 2;
        }
        for (int i = 0; i < (n / 2); i++)
        {
            for (j = 1; j <= 1000; j++)
            {
                if (cnt[j] > 1)
                    break;
            }
            if (j > 1000)
            {
                cout << "NO" << endl;
                return 0;
            }
            a[i][n / 2] = j;
            a[n - 1 - i][n / 2] = j;
            cnt[j] -= 2;
        }
        for (j = 1; j <= 1000; j++)
        {
            if (cnt[j])
                break;
        }
        if (j > 1000)
        {
            cout << "NO" << endl;
            return 0;
        }
        a[n / 2][n / 2] = j;
    }
    cout << "YES" << endl;
    for (int i = 0; i < prak; i++)
    {
        for (int j = 0; j < prak; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
    return 0;
}