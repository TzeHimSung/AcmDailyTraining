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
    int ans = 0;
    int minCameraCover(TreeNode *root) {

        // 0: 节点附近有未被监视的节点，需安装监视器
        // 1: 节点附近有监视器或该节点不存在，不需要装监视器
        // 2: 节点附近没有监视器，需要装监视器
        function<int(TreeNode *)> dfs = [&](TreeNode * cur) {
            if (cur == nullptr) return 1;
            int left = dfs(cur->left), right = dfs(cur->right);
            if (left == 2 || right == 2) {
                ans++;
                return 0;
            } else if (left == 0 || right == 0) {
                return 1;
            } else {
                return 2;
            }
        };

        if (dfs(root) == 2) ans++;
        return ans;
    }
};