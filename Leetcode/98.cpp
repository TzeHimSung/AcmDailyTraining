// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//  * };
//  */
// class Solution {
// public:
//     bool isValidBST(TreeNode *root) {
//         vector<int> value;

//         function<void(TreeNode *)> dfs = [&](TreeNode * cur) {
//             if (cur == nullptr) return;
//             dfs(cur->left);
//             value.push_back(cur->val);
//             dfs(cur->right);
//         };

//         dfs(root);

//         int flag = true;
//         for (int i = 0; i < value.size(); i++) {
//             if (i && value[i] <= value[i - 1]) {
//                 flag = false;
//                 break;
//             }
//         }

//         return flag;
//     }
// };

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
    TreeNode *lastNode = nullptr;
    bool isValidBST(TreeNode *root) {
        if (!root) return true;
        if (!isValidBST(root->left)) return false;
        if (lastNode && lastNode->val >= root->val) return false;
        lastNode = root;
        if (!isValidBST(root->right)) return false;
        return true;
    }
};