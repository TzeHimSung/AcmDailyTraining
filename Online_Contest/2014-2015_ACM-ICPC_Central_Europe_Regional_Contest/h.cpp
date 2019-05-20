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
#define sot(a,b) sort(a+1,a+1+b)
#define rep1(i,a,b) for(int i=a;i<=b;++i)
#define rep0(i,a,b) for(int i=a;i<b;++i)
#define repa(i,a) for(auto &i:a)
#define eps 1e-8
#define int_inf 0x3f3f3f3f
#define ll_inf 0x7f7f7f7f7f7f7f7f
#define lson curPos<<1
#define rson curPos<<1|1
/* namespace */
using namespace std;
/* header end */

set<int>num;
vector<int>v[10];
const int px[] = {4, 1, 1, 1, 2, 2, 2, 3, 3, 3};
const int py[] = {2, 1, 2, 3, 1, 2, 3, 1, 2, 3};

void dfs(int curDig, int curNum, int len)
{
    curNum += curDig; num.insert(curNum);
    if (len > 3) return;
    rep0(i, 0, v[curDig].size())
    dfs(v[curDig][i], curNum * 10, len + 1);
}

int main()
{
    rep1(i, 0, 9)
    {
        rep1(j, 0, 9)
        if (px[i] <= px[j] && py[i] <= py[j])
            v[i].pb(j);
    }
    rep1(i, 0, 9) dfs(i, 0, 0);
    int t; scanf("%d", &t);
    while (t--)
    {
        int n; scanf("%d", &n);
        set<int>::iterator it = num.lower_bound(n);
        int a = *it;
        if (it != num.begin())
        {
            int b = *(--it);
            if (n - b < a - n) a = b;
        }
        printf("%d\n", a);
    }
    return 0;
}