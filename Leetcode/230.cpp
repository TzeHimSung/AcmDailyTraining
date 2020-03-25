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
    int kthSmallest(TreeNode *root, int k) {
        int left = countChild(root->left);
        if (left + 1 == k) return root->val;
        if (k <= left) return kthSmallest(root->left, k);
        else return kthSmallest(root->right, k - 1 - left);
    }

    int countChild(TreeNode *root) {
        if (root == nullptr) return 0;
        return countChild(root->left) + countChild(root->right) + 1;
    }
};
