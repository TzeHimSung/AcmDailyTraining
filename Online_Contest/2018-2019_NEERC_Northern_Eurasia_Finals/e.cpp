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
#define int int32_t
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

const int maxn = 10;
int n, a[10][10];

int main()
{
    cin >> n;
    printf("a1 ");
    a[1][1] = a[8][8] = 1;
    int curX = 1, curY = 1; --n;
    while (n--)
    {
        if (n <= 6 && curX != 8 && curY != 8)
            curY = 8;
        else
        {
            int nX = 0;
            for (int i = 8; i > 0; i--)
                if (!a[i][curY])
                {
                    nX = i;
                    break;
                }
            if (nX != 0)
                curX = nX;
            else
                curY++;
        }
        a[curX][curY] = 1;
        printf("%c%d ", 'a' + curX - 1, curY);
    }
    puts("h8");
    return 0;
}