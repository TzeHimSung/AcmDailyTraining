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

map<int, int> front, back, dist;

bool parity(const string &s) {
    bool ret = false;
    for (auto i = s.begin(); i != s.end(); ++i)
        for (auto j = i + 1; j != s.end(); ++j)
            if (*i > *j) ret = !ret;
    return ret;
}

string swap(const string &s, int i, int j) {
    string ret(s);
    ret[i] = s[j]; ret[j] = s[i];
    return ret;
}

bool bfs(const vector<vector<int>> &edges) {
    queue<int> q;
    for (auto i : front) {
        if (i.second == -1) {
            dist[i.first] = 0;
            q.push(i.first);
        } else {
            dist[i.first] = int_inf;
        }
    }
    dist[-1] = int_inf;
    while ((int)q.size()) {
        int u = q.front();
        q.pop();
        if (dist[u] < dist[-1]) {
            for (auto v : edges[u]) {
                auto curr = back.find(v);
                if (dist[curr->second] == int_inf) {
                    dist[curr->second] = dist[u] + 1;
                    q.push(curr->second);
                }
            }
        }
    }

    return dist[-1] != int_inf;
}

bool dfs(const vector<vector<int>> &edges, int u, map<int, int> *front, map<int, int> *back, map<int, int> &dist) {
    if (u == -1) return true;
    for (auto v : edges[u]) {
        if (dist.find((*back)[v])->second == dist.find(u)->second + 1) {
            if (dfs(edges, (*back)[v], front, back, dist)) {
                (*front)[u] = v; (*back)[v] = u;
                return true;
            }
        }
    }
    return false;
}

int main() {
    int n; cin >> n;
    vector<string> words(n);
    unordered_map<string, int> index;
    vector<vector<int>> edges(n), pwords(2);
    for (int i = 0; i < n; ++i) {
        cin >> words[i];
        index[words[i]] = i;
    }
    int __size = words[0].size();
    for (int i = 0; i < n; ++i) {
        int p = (int)parity(words[i]);
        pwords[p].push_back(i);
        if (!p) {
            for (int a = 0; a < __size; ++a) {
                for (int b = a + 1; b < __size; ++b) {
                    auto s = swap(words[i], a, b);
                    auto si = index.find(s);
                    if (si != index.end())
                        edges[i].push_back(si->second);
                }
            }
        }
    }
    for (auto i : pwords[0]) front[i] = -1;
    for (auto i : pwords[1]) back[i] = -1;
    for (int i = 0; i < n; ++i) dist[i] = int_inf;
    // flow
    while (bfs(edges))
        for (auto i : front)
            if (i.second == -1) dfs(edges, i.first, &front, &back, dist);
    int total_flow = 0;
    for (auto i : front) total_flow += (i.second != -1);
    cout << n - total_flow << endl;
    return 0;
}

