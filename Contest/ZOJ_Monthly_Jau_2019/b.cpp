#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

using ll = long long;

inline ll read() {
	ll d = 0, f = 1; 
	char s = getchar();
	while (s < '0' || s > '9') {
		if (s == '-')
			f = -1;
		s = getchar();
	}
	while (s >= '0' && s <= '9') {
		d = d * 10 + s - '0';
		s = getchar();
	}
	return d * f;
}

int const N = 1e5 + 5;

struct edge {
	int y, next;
}a[N], totx[N];
int lasta[N], ne, lastx[N], xne;
int n, m;

void add(int x, int y) {
	a[++ne].y = y;
	a[ne].next = lasta[x]; 
	lasta[x] = ne;
}

void addtot(int y, int x) {
	totx[++xne].y = x;
	totx[xne].next = lastx[y];
	lastx[y] = xne;
}

int solve(ll s) {
	for (int i = 1; i <= n; ++i)
		lastx[i] = 0;
	xne = 0;
	int ret = 0, ansy = n;
	ll sumx = 0, sumy = 0, sump = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = lasta[i]; j != 0; j = a[j].next) {
			int y = a[j].y;
			if (y <= ansy) {
				sumx += i;
				sumy += y;
				++sump;
				addtot(y, i);
			}
		}

		while (sump * (i + ansy) - sumx - sumy > s) {
			for (int j = lastx[ansy]; j != 0; j = totx[j].next) {
				int x = totx[j].y;
				sumx -= x;
				--sump;
				sumy -= ansy;
			}
			--ansy;
		}

		if (sump * (i + ansy) - sumx - sumy == s)
			++ret;
	}
	return ret;
}

int main() {
	int T = read();
	while (T--) {
		n = read(), m = read();
		for (int i = 1; i <= n; ++i)
			lasta[i] = 0;
		ne = 0;

		for (int i = 1; i <= m; ++i) {
			int x = read(), y = read();
			add(x, y);
		}

		int Q = read();
		while (Q--) {
			ll x = read();
			printf("%d", solve(x));
			if (Q == 0) 
				putchar('\n');
			else 
				putchar(' ');
		}
	}
}