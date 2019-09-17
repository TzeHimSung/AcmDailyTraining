#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

vector<char>g[26];
int vis[26], inDeg[26];
set<char>point;

void init() {
    for (int i = 0; i < 26; i++) {
        g[i].clear();
        vis[i] = inDeg[i] = 0;
    }
    point.clear();
    for (int i = 0; i < 6; i++) point.insert(char('a' + i));
}

void buildDirectedGraph() {
    init();
    g['a' - 'a'].emplace_back('b'); inDeg['b' - 'a']++;
    g['a' - 'a'].emplace_back('c'); inDeg['c' - 'a']++;
    g['b' - 'a'].emplace_back('d'); inDeg['d' - 'a']++;
    g['c' - 'a'].emplace_back('e'); inDeg['e' - 'a']++;
    g['c' - 'a'].emplace_back('f'); inDeg['f' - 'a']++;
    g['d' - 'a'].emplace_back('c'); inDeg['c' - 'a']++;
    g['f' - 'a'].emplace_back('e'); inDeg['e' - 'a']++;
    for (int i = 0; i < 26; i++) {
        if (!g[i].empty())
            sort(g[i].begin(), g[i].end());
    }
}

void buildUndirectedGraph() {
    init();
    g['a' - 'a'].emplace_back('b'); g['b' - 'a'].emplace_back('a');
    g['a' - 'a'].emplace_back('c'); g['c' - 'a'].emplace_back('a');
    g['b' - 'a'].emplace_back('d'); g['d' - 'a'].emplace_back('b');
    g['c' - 'a'].emplace_back('e'); g['e' - 'a'].emplace_back('c');
    g['c' - 'a'].emplace_back('f'); g['f' - 'a'].emplace_back('c');
    g['d' - 'a'].emplace_back('c'); g['c' - 'a'].emplace_back('d');
    g['f' - 'a'].emplace_back('e'); g['e' - 'a'].emplace_back('f');
    for (int i = 0; i < 26; i++)
        if (!g[i].empty())
            sort(g[i].begin(), g[i].end());
}

int findZeroDegreePoint() {
    for (int i = 0; i < 26; i++)
        if (point.count(char('a' + i)) && !vis[i] && !inDeg[i])
            return i;
    return -1;
}

void topologicalSort() {
    while (1) {
        int curr = findZeroDegreePoint();
        if (curr == -1) break;
        cout << char('a' + curr) << " ";
        vis[curr] = 1;
        for (auto i : g[curr]) inDeg[i - 'a']--;
    }
}

void dfs(char curr) {
    cout << curr << " ";
    vis[curr - 'a'] = 1;
    for (auto i : g[curr - 'a']) {
        if (!vis[i - 'a']) dfs(i);
    }
}

int main() {
    // topological sort
    buildDirectedGraph();
    cout << "The topological sort sequence is: ";
    topologicalSort();
    cout << endl;

    // dfs
    buildUndirectedGraph();
    cout << "The DFS sequence is: ";
    for (int i = 0; i < 26; i++) {
        if (!g[i].empty()) {
            dfs(char('a' + i));
            break;
        }
    }
    cout << endl;

    // bfs
    buildUndirectedGraph();
    cout << "The BFS sequence is: ";
    queue<char>q;
    while (!q.empty()) q.pop();
    for (int i = 0; i < 26; i++) {
        if (!g[i].empty()) {
            q.push(char('a' + i));
            break;
        }
    }
    while (!q.empty()) {
        char curr = q.front();
        q.pop();
        if (vis[curr - 'a']) continue;
        cout << curr << " ";
        vis[curr - 'a'] = 1;
        for (auto i : g[curr - 'a']) q.push(i);
    }
    cout << endl;
    return 0;
}