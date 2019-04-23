#include <bits/stdc++.h>

using namespace std;

const int maxm = 1e5 + 10;
struct Edge
{
    int to, w, next;
};

Edge edge[maxm]; //从0开始
int cnt, head[maxm];

void addEdge(int u, int v, int w)
{
    edge[cnt].w = w;
    edge[cnt].to = v;
    edge[cnt].next = head[u]; //head[x]是以x为起点的边在edge数组中最后一次出现的位置
    head[u] = cnt++;
}

int main()
{
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; i++) head[i] = -1;
    for (int i = 1; i <= n; i++)
    {
        int a, b, c; scanf("%d%d%d", &a, &b, &c);
        addEdge(a, b, c);
    }
    //output
    int start; scanf("%d", &start);
    for (int i = head[start]; i != -1; i = edge[i].next)
        printf("from %d to %d weight %d\n", start, edge[i].to, edge[i].w);
    return 0;
}