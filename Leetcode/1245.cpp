class Solution {
public:
    int treeDiameter(vector<vector<int>> &edges) {
        int max = 0, endpoint = -1;
        vector<vector<int>> tree(edges.size() + 1);
        vector<bool> vis(edges.size() + 1, false);

        for (auto e : edges) {
            tree[e[0]].push_back(e[1]);
            tree[e[1]].push_back(e[0]);
        }

        function<void(int, int)> dfs = [&](int start, int sum) {
            if (vis[start]) return;
            vis[start] = true;
            for (auto node : tree[start]) {
                dfs(node, sum + 1);
            }
            if (max < sum) {
                max = sum;
                endpoint = start;
            }
        };

        dfs(edges[0][0], 0);
        vis.assign(vis.size(), false);
        dfs(endpoint, 0);
        return max;
    }
};