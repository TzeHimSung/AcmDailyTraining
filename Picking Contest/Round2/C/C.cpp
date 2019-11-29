// Cease to struggle and you cease to live
// 3252攻略.cpp
// Created on 2017-11-07 09:49
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
inline int read() {
	int x = 0, ch = getchar(); bool fg = 1;
	while(ch < '0' || ch > '9') { if(ch == '-') fg = 0; ch = getchar(); } 
	while(ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return fg ? x : -x;
}
const int MAXN = 200003;
struct Edge {
	int to, nxt;
	Edge() {}
	Edge(int _to, int _nxt):to(_to), nxt(_nxt) {}
}e[MAXN << 1];
int h[MAXN], p;
int fa[MAXN], son[MAXN], top[MAXN];
long long dep[MAXN], mx[MAXN];
int w[MAXN];
priority_queue<long long> q;
inline void add_edge(int u, int v) {
	e[++p] = Edge(v, h[u]); h[u] = p;
	e[++p] = Edge(u, h[v]); h[v] = p;
}
void dfs1(int x) {
	mx[x] = dep[x];
	for(int i = h[x]; i; i = e[i].nxt) {
		int y = e[i].to;
		if(y == fa[x]) continue;
		fa[y] = x;
		dep[y] = dep[x] + w[y];
		dfs1(y);
		if(mx[y] > mx[son[x]]) son[x] = y;
		mx[x] = max(mx[x], mx[y]);
	}
}
void dfs2(int x) {
	if(son[x]) {
		top[son[x]] = top[x];
		dfs2(son[x]);
	}
	for(int i = h[x]; i; i = e[i].nxt) {
		int y = e[i].to;
		if(y == fa[x] || y == son[x]) continue;
		top[y] = y;
		dfs2(y);
	}
}
int main() {
	int n = read(), m = read();
	for(int i = 1; i <= n; i++) w[i] = read();
	for(int i = 1; i < n; i++) add_edge(read(), read());
	fa[1] = 0; dep[1] = w[1]; top[1] = 1;
	dfs1(1); dfs2(1);
	long long ans = 0;
	for(int i = 1; i <= n; i++) if(top[i] == i) {
		q.push(mx[i] - dep[fa[i]]);
	}
	while(!q.empty() && m--) {
		ans += q.top(), q.pop();
	}
	printf("%lld\n", ans);
	return 0;
}

