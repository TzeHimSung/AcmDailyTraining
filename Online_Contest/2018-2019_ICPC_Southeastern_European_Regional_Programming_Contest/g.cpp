/* basic header */
#include <bits/stdc++.h>
/* define */
#define ll long long
#define pb emplace_back
#define mp make_pair
#define eps 1e-8
#define lson (curpos<<1)
#define rson (curpos<<1|1)
/* namespace */
using namespace std;
/* header end */

const int MAXN = (1 << 20) + 1;
ll totalMatrix = 0, segT[2][MAXN << 2], state[2][21];
int n, m, _size;

void update(int id, int pos, int curpos, int curl, int curr, int depth) {
    if (curl == curr) {
        segT[id][curpos] ^= 1;
        return;
    }
    int mid = curl + curr >> 1;
    if (pos <= mid) update(id, pos, lson, curl, mid, depth + 1);
    else update(id, pos, rson, mid + 1, curr, depth + 1);
    if (segT[id][curpos] != -1) state[id][depth]--;
    if (segT[id][lson] == segT[id][rson]) segT[id][curpos] = segT[id][lson];
    else segT[id][curpos] = -1;
    if (segT[id][curpos] != -1) state[id][depth]++;
}

void read(int &x) {
    char ch = getchar();
    x = 0;
    for (; ch < '0' || ch > '9'; ch = getchar());
    for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + (ch - '0');
}

void write(ll x) {
    char ch = x % 10 + '0';
    if (x >= 10) write(x / 10);
    putchar(ch);
}

int main() {
    read(_size); read(m);
    n = (1 << _size);
    for (int i = 0; i < _size; i++) {
        state[0][i + 1] = state[1][i + 1] = (1 << i);
        totalMatrix += (1LL << (i << 1));
    }
    for (int i = 0; i < m; i++) {
        int id, x; read(id); read(x);
        update(id, x, 1, 1, n, 1);
        ll tmp = 0;
        for (int i = 1; i <= _size; i++)
            tmp += state[0][i] * state[1][i];
        write(4LL * (totalMatrix - tmp) + 1);
        puts("");
    }
    return 0;
}