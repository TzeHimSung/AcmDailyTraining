//#pragma comment(linker, "/STACK:102400000,102400000")
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <functional>
using namespace std;
const long long INF = 1LL << 60;
const int MAXN = 200011;
typedef pair <long long, int>P;
priority_queue<P, vector<P>, greater<P> > q;
int L[MAXN], R[MAXN], W[MAXN];
long long d[MAXN];
int fa[MAXN];
int n;

void init() {
	for(int i = 1; i <= n; i++) {
		d[i] = INF;
		fa[i] = i;
	}
}

int Find(int x) { return x == fa[x] ? x : fa[x] = Find(fa[x]); }

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		init();
		for(int i = 1; i <= n; i++) scanf("%d", L + i);
		for(int i = 1; i <= n; i++) scanf("%d", R + i);
		for(int i = 1; i <= n; i++) scanf("%d", W + i);

		d[1] = W[1];
		q.push(make_pair(0LL, 1));
		while(!q.empty()) {
			P x = q.top(); q.pop();
			int u = x.second;
			for(int ch = -1; ch<= 1; ch += 2) {
				int l = u + L[u] * ch;
				int r = u + R[u] * ch;
				if(l > r) swap(l, r);
				l = min(max(1, l), n + 1);
				if(l > r) continue;
				for(int v = l; ; v++) {
					v = Find(v);
					if(v <= 0 || v > n || v > r) break;
					if(d[v] > d[u] + W[v]) {
						d[v] = d[u] + W[v];
						q.push(make_pair(d[v], v));
					}
					fa[Find(v)] = Find(v + 1);
				}
			}
		}
		printf("0");
		for(int i = 2; i <= n; i++) printf(" %lld", d[i] == INF ? -1 : d[i] - W[i]);
		printf("\n");
	}
	return 0;
}
