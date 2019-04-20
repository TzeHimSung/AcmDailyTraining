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

ll n, k, a, b;
vector<int>v;

template<class T>
istream &operator >> (istream &X, vector<T> &Y)
{
    for (auto &x : Y) cin >> x;
    return X;
}

ll calc(int l, int r)
{
    //the delta value is the num of heros
    return upper_bound(v.begin(), v.end(), r) - upper_bound(v.begin(), v.end(), l - 1);
}

ll solve(int pos, int N)
{
    int sum = calc(pos, pos + (1 << N) - 1);
    if (!sum)
        return a;
    if (!N)
        return sum * b * 1;
    return min(sum * b * (1 << N), solve(pos, N - 1) + solve(pos + (1 << N - 1), N - 1));
}

int main()
{
    cin >> n >> k >> a >> b;
    v.resize(k); //resize之后就可以直接cin了
    cin >> v;
    sort(v.begin(), v.end());
    cout << solve(1, n) << endl;
    return 0;
}