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
#define ll_inf 0x7f7f7f7f7f7f7f7f
#define lson curPos<<1
#define rson curPos<<1|1
/* namespace */
using namespace std;
/* header end */

const int maxn = 1e3 + 10;
const int maxk = 1e2 + 10;
int n, k, a[maxn], job[maxk], id[maxk], testNum[maxk];
bool vis[maxn];
queue<pair<int, int>>q;

int main()
{
    while (!q.empty()) q.pop();
    cin >> n >> k;
    rep0(i, 0, n)
    {
        cin >> a[i];
        q.push(mp(a[i], i));
    }
    init(job, -1);
    for (int cnt = 0, sign = 1; sign;)
    {
        sign = 0;
        rep0(i, 0, k)
        {
            if (job[i] == testNum[i] || job[i] == -1)
            {
                if (~job[i]) cnt++;
                job[i] = 1;
                if ((int)q.size())
                {
                    testNum[i] = q.front().first;
                    id[i] = q.front().second;
                    q.pop();
                    sign = 1;
                }
                else testNum[i] = int_inf, job[i] = int_inf - 1;
            }
            else if (testNum[i] != int_inf)
                job[i]++, sign = 1;
        }
        rep0(i, 0, k)
        if ((int)floor(0.5 + 1.0 * cnt / n * 100) == job[i])
            vis[id[i]] = 1;
    }
    int ans = 0;
    rep0(i, 0, n) if (vis[i]) ans++;
    cout << ans << endl;
    return 0;
}