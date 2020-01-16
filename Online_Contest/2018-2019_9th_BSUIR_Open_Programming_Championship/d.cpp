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
struct Node {
    int id, x;
    Node() {}
    Node(int _id, int _x): id(_id), x(_x) {}
    bool operator<(const Node &rhs)const {
        return x < rhs.x || x == rhs.x && id < rhs.id;
    }
} card[maxn];
pair<int, int> dp[maxn], segT[maxn << 2];
int n, pass, numOfCard = 0, ans = 0, __begin = 0;

void maintain(int curpos) {
    segT[curpos] = max(segT[lson], segT[rson]);
}

void build(int curpos, int curl, int curr) {
    if (curl == curr) {
        segT[curpos] = mp(0, -1);
        return;
    }
    int mid = curl + curr >> 1;
    build(lson, curl, mid); build(rson, mid + 1, curr);
    maintain(curpos);
}

pair<int, int> query(int curpos, int curl, int curr, int ql, int qr) {
    if (ql > qr) return mp(0, -1);
    if (ql <= curl && curr <= qr) return segT[curpos];
    int mid = curl + curr >> 1;
    pair<int, int> ans = mp(0, -1);
    if (ql <= mid) ans = max(ans, query(lson, curl, mid, ql, qr));
    if (qr > mid) ans = max(ans, query(rson, mid + 1, curr, ql, qr));
    return ans;
}

void update(int curpos, int pos, int curl, int curr, pair<int, int>val) {
    if (curl == curr) {
        segT[curpos] = max(segT[curpos], val);
        return;
    }
    int mid = curl + curr >> 1;
    if (pos <= mid) update(lson, pos, curl, mid, val);
    else update(rson, pos, mid + 1, curr, val);
    maintain(curpos);
}

void dfs(int curr, int depth) {
    if (curr == -1) {
        printf("%d\n", depth);
        return;
    }
    dfs(dp[curr].second, depth + 1);
    printf("%d %d\n", card[curr].id, card[curr].x);
}

int main() {
    scanf("%d%d", &n, &pass);
    for (int i = 1; i <= n; i++) {
        int num; scanf("%d", &num);
        for (int j = 1; j <= num; j++) {
            int x; scanf("%d", &x);
            card[++numOfCard] = Node(i, x);
        }
    }
    build(1, 1, n);
    sort(card + 1, card + 1 + numOfCard);
    // O(n^2logn) LIS
    for (int i = 1; i <= numOfCard;) {
        for (int j = i; j <= numOfCard; j++) {
            if (card[i].x != card[j].x) break;
            int currID = card[j].id, currPos = ((currID - pass - 2) % n + n) % n + 1;
            if (currPos < currID) dp[j] = query(1, 1, n, currPos, currID - 1);
            else dp[j] = max(query(1, 1, n, currPos, n), query(1, 1, n, 1, currID - 1));
        }
        int j;
        for (j = i; j <= numOfCard; j++) {
            if (card[i].x != card[j].x) break;
            if (!dp[j].first && card[j].id > pass + 1) continue;
            dp[j].first++; int pos = card[j].id;
            update(1, pos, 1, n, mp(dp[j].first, j));
        }
        i = j;
    }
    for (int i = 1; i <= numOfCard; i++)
        if (dp[i].first > ans) {
            ans = dp[i].first;
            __begin = i;
        }
    if (!__begin) puts("0");
    else dfs(__begin, 0);
    return 0;
}