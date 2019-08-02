/* basic header */
#include <bits/stdc++.h>
/* define */
#define ll long long
#define dou double
#define pb emplace_back
#define mp make_pair
#define sot(a,b) sort(a+1,a+1+b)
#define rep1(i,a,b) for(int i=a;i<=b;++i)
#define rep0(i,a,b) for(int i=a;i<b;++i)
#define eps 1e-8
#define int_inf 0x3f3f3f3f
#define ll_inf 0x7f7f7f7f7f7f7f7f
#define lson (curpos<<1)
#define rson (curpos<<1|1)
/* namespace */
using namespace std;
/* header end */

const int maxn = 1e5 + 10;
struct Edge {
    int to, next;
    Edge() {}
    Edge(int to, int next): to(to), next(next) {}
} edge[maxn * 10];
int head[maxn], inDeg[maxn], tot = 0, realMem[maxn * 10];
char str[maxn], op[maxn];
vector<int>vec, realPos[20];

void addEdge(int u, int v) {
    edge[tot].to = v;
    edge[tot].next = head[u];
    inDeg[v]++;
    head[u] = tot++;
}

int topologicalSort(int n) {
    queue<int>q;
    for (int i = 1; i <= n; i++)
        if (!inDeg[i]) q.push(i); // 找最小的点
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        vec.pb(u);
        for (int i = head[u]; ~i; i = edge[i].next) {
            int v = edge[i].to;
            inDeg[v]--;
            if (!inDeg[v]) q.push(v);
        }
    }
    if (n == vec.size()) return 1; // 如果构建出来的图大小也为n，说明有解
    else return 0;
}

int main() {
    int n, m; scanf("%d%d", &n, &m);
    m = m * (m - 1) >> 1;
    for (int i = 0; i < maxn; i++) head[i] = -1;
    int realLen = 0;
    while (m--) {
        int len;
        scanf("%s %d", op, &len);
        if (len != 0) scanf("%s", str);
        int lastElement = -1;
        int times[26];
        memset(times, 0, sizeof(times));
        for (int i = 0; i < len; i++) {
            int currElement = str[i] - 'a';
            times[currElement]++; // 统计当前字符串中当前字母出现次数
            if (realPos[currElement].size() < times[currElement]) { // 如果当前字符串中的某个字母出现次数超出了之前的统计，说明该字母有更多个
                realPos[currElement].pb(++realLen);
                realMem[realLen] = currElement;
            }
            if (lastElement != -1) addEdge(lastElement, realPos[currElement][times[currElement] - 1]);
            lastElement = realPos[currElement][times[currElement] - 1];
        }
    }
    if (n != realLen) return puts("-1"), 0;
    if (topologicalSort(n))
        for (int i = 0; i < vec.size(); i++)
            printf("%c", 'a' + realMem[vec[i]]);
    else puts("-1");
    return 0;
}