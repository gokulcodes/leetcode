/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    int dfs(TreeNode* root, int mn){
        if(root == NULL) return 0;
        int res = root->val >= mn ? 1 : 0;
        res += dfs(root->left, max(mn, root->val));
        res += dfs(root->right, max(mn, root->val));
        return res;
    }
    
    int goodNodes(TreeNode* root) {
        return dfs(root, INT_MIN);
    }
};