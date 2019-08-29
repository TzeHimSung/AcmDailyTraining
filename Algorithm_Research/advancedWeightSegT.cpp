const int maxn = 1e5 + 10;
struct Node {
    int l, r, sum; //l r是左右子树根节点编号, sum是该节点对应区间内数的个数
};

Node segt[maxn * 25];
vector<int>v;
int n, m, cnt = 0, root[maxn], a[maxn];

int getid(int x) { //返回数值x在数组v中的位置
    return lower_bound(v.begin(), v.end(), x) - v.begin() + 1;
}

void update(int curl, int curr, int &cur, int last, int pos) { //cur是当前版本树的根节点的编号，last是上一版本树的根节点的编号
    cnt++;
    segt[cnt] = segt[last];
    segt[cnt].sum++;
    cur = cnt;
    if (curl == curr) return;
    int mid = (curl + curr) >> 1;
    if (pos <= mid) update(curl, mid, segt[cur].l, segt[last].l, pos); //往左递归
    else update(mid + 1, curr, segt[cur].r, segt[last].r, pos);
}

int query(int curl, int curr, int rql, int rqr, int k) {
    if (curl == curr) return curl;
    int mid = (curl + curr) >> 1, sum = segt[segt[rqr].l].sum - segt[segt[rql].l].sum;
    if (sum >= k) return query(curl, mid, segt[rql].l, segt[rqr].l, k);
    else return query(mid + 1, curr, segt[rql].r, segt[rqr].r, k - sum);
}

int main() {
    scanf("%d%d", &n, &m);
    rep1(i, 1, n) {
        scanf("%d", &a[i]);
        v.push_back(a[i]);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end()); //v是a数组排序并去重的结果
    rep1(i, 1, n) //n次update,建n棵权值线段树
    update(1, n, root[i], root[i - 1], getid(a[i])); //root[i]代表a[1..i]这个区间弄出来的权值线段树的根节点
    rep1(i, 1, m) {
        int x, y, k; scanf("%d%d%d", &x, &y, &k);
        printf("%d\n", v[query(1, n, root[x - 1], root[y], k) - 1]);
    }
    return 0;
}
