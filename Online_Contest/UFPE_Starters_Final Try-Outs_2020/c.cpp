#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
using namespace std;
#define N 1000010
#define INF 0x7fffffff
struct trie_node {
    int k[26];
    int mind;
    int minx;
    int f;
    int c;
    int end;
};
struct trie {
    trie_node tr[N];
    int index[N];
    int num;
    void clear() {
        memset(tr, 0, sizeof(tr));
        tr[0].mind = INF;
        num = 0;
    }
    void insert(char ch[], int ind) {
        int len = strlen(ch);
        int now = 0;
        for (int i = 0; i < len; ++i) {
            int t = ch[i] - 'a';
            if (tr[now].k[t] == 0) {
                ++num;
                tr[num].f = now;
                tr[num].c = t;
                tr[num].mind = INF;
                tr[num].end = 0;
                tr[now].k[t] = num;
            }
            if (tr[now].mind > len - i) {
                tr[now].mind = len - i;
                tr[now].minx = t;
            }
            now = tr[now].k[t];
        }
        tr[now].mind = 0;
        tr[now].end = ind;
        index[ind] = now;
    }
    void remove(int ind) {
        int now = index[ind];
        index[ind] = 0;
        tr[tr[now].f].k[tr[now].c] = 0;

        while (now != 0) {
            if (!tr[now].end) {
                int mind = INF;
                int minx = 0;
                for (int i = 0; i < 26; ++i)
                    if (tr[now].k[i] > 0 && mind > tr[tr[now].k[i]].mind) {
                        mind = tr[tr[now].k[i]].mind;
                        minx = i;
                    }
                if (mind != INF) {
                    tr[now].mind = mind + 1;
                    tr[now].minx = minx;
                } else {
                    tr[tr[now].f].k[tr[now].c] = 0;
                }
            }
            now = tr[now].f;
        }
    }
    int query(char ch[]) {
        int len = strlen(ch);
        int now = 0;
        for (int i = 0; i < len; ++i) {
            int t = ch[i] - 'a';
            if (tr[now].k[t] == 0) return -1;
            now = tr[now].k[t];
        }
        while (!tr[now].end) {
            now = tr[now].k[tr[now].minx];
        }
        return tr[now].end;
    }
};
trie map;
char ch[1000011];
int main() {
    map.clear();
    int Q;
    scanf("%d", &Q);
    for (int ind = 1; ind <= Q; ++ind) {
        int op;
        scanf("%d", &op);
        if (op == 1) {
            scanf("%s", ch);
            map.insert(ch, ind);
        } else if (op == 2) {
            int rid;
            scanf("%d", &rid);
            map.remove(rid);
        } else {
            scanf("%s", ch);
            printf("%d\n", map.query(ch));
        }
    }
}