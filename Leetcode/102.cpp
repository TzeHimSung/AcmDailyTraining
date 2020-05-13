/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        vector<vector<int>> ret;

        function<void(TreeNode *, int)> dfs = [&](TreeNode * cur, int depth) {
            if (!cur) return;
            if (ret.size() < depth) ret.push_back(vector<int> {});
            ret[depth - 1].push_back(cur->val);
            dfs(cur->left, depth + 1), dfs(cur->right, depth + 1);
        };

        dfs(root, 1);

        return ret;
    }
};