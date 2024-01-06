#include<bits/stdc++.h>

using namespace std;
using ll = long long;

struct Node {
    string name;
    int contribute, level, job, id;
};

bool cmp(const Node& A, const Node& B) {
    return A.contribute == B.contribute ? A.id<B.id : A.contribute>B.contribute;
}
bool cmp_(const Node& A, const Node& B) {
    return A.job == B.job ? A.level == B.level ? A.id<B.id : A.level>B.level : A.job < B.job;
}

void solve() {
    int n;
    cin >> n;
    map<string, int> mp;
    vector<int> num{ 1,3,5,9,16,41,113 };
    vector<string> job_name{ "BangZhu", "FuBangZhu","HuFa", "ZhangLao","TangZhu", "JingYing", "BangZhong" };
    vector<Node> a(n + 1);
    for (int i = 0;i < 7;i++)
        mp[job_name[i]] = i;
    for (int i = 1;i <= n;i++) {
        a[i].id = i;
        string s;
        cin >> a[i].name >> s;
        a[i].job = mp[s];
        cin >> a[i].contribute >> a[i].level;
    }
    sort(a.begin() + 4, a.end(), cmp);
    for (int i = 4;i <= n;i++)
        for (int j = 2;j < 7;j++)
            if (i <= num[j]) {
                a[i].job = j;
                break;
            }
    sort(a.begin() + 1, a.end(), cmp_);
    for (int i = 1;i <= n;i++)
        cout << a[i].name << ' ' << job_name[a[i].job] << ' ' << a[i].level << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
