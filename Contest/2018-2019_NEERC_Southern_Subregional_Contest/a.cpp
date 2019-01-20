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

const int maxn = 5e5 + 10;
struct Node
{
    int len, mod, sum;
    char c[600];
    Node()
    {
        len = mod = sum = 0;
        init(c, 0);
    }
};

bool vis[510][maxn];
queue<Node>q;

void print(Node tmp)
{
    rep0(i, 0, tmp.len)
    printf("%c", tmp.c[i]);
    puts("");
}

int main()
{
    while (!q.empty()) q.pop();
    int d, s;
    scanf("%d%d", &d, &s);
    Node h;
    q.push(h);
    while (!q.empty())
    {
        h = q.front();
        q.pop();
        rep1(i, 0, 9)
        {
            Node tmp = h;
            tmp.c[tmp.len++] = i + '0';
            tmp.sum += i;
            tmp.mod = (tmp.mod * 10 + i) % d;
            if (tmp.sum > s || vis[tmp.mod][tmp.sum]) continue;
            vis[tmp.mod][tmp.sum] = 1;
            if (!tmp.mod && tmp.sum == s)
            {
                print(tmp);
                return 0;
            }
            q.push(tmp);
        }
    }
    puts("-1");
    return 0;
}