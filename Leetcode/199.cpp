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
    vector<int> rightSideView(TreeNode *root) {
        int maxDepth = 0;
        vector<int> ret = {};

        function<void(TreeNode *, int)> dfs = [&](TreeNode * node, int depth) {
            if (node == nullptr) return;
            if (depth == maxDepth) {
                maxDepth++;
                ret.push_back(node->val);
            }
            dfs(node->right, depth + 1), dfs(node->left, depth + 1);
        };

        dfs(root, 0);

        return ret;
    }
};