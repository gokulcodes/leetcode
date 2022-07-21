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
    
    bool dfs(TreeNode* root){
        if(root->left == NULL and root->right == NULL) return root->val;
        
        int cond = root->val;
        int left = dfs(root->left);
        int right = dfs(root->right);
        
        if(cond == 2) return left || right;
        
        return left and right;
        
    }
    
    bool evaluateTree(TreeNode* root) {
        return dfs(root);
    }
};