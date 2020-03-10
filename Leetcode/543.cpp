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
private:
    int ret = 0;

    int dfs(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }
        int leftH = dfs(root->left), rightH = dfs(root->right);
        ret = max(ret, leftH + rightH);
        return max(leftH, rightH) + 1;
    }

public:
    int diameterOfBinaryTree(TreeNode *root) {
        dfs(root);
        return ret;
    }
};