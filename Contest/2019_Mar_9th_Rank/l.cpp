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

int t, n, m;
map<string, int>totalTime;
set<string>s;

int getTime(string ss)
{
    int hh = 10 * (ss[0] - '0') + ss[1] - '0';
    int mm = 10 * (ss[3] - '0') + ss[4] - '0';
    return hh * 60 + mm;
}

int main()
{
    cin >> t;
    while (t--)
    {
        int ac = 0, total = 0;
        totalTime.clear(); s.clear();
        cin >> n >> m;
        while (m--)
        {
            string a, b, c; cin >> a >> b >> c;
            if (c == "AC")
            {
                if (s.count(a)) continue;
                s.insert(a);
                if (!totalTime.count(a)) totalTime[a] = 0;
                totalTime[a] += getTime(b);
                ac++;
            }
            else
            {
                if (s.count(a)) continue;
                if (!totalTime.count(a)) totalTime[a] = 0;
                totalTime[a] += 20;
            }

        }
        for (auto i : s) total += totalTime[i];
        cout << ac << " " << total << endl;
    }
    return 0;
}