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
    
    bool dfs(TreeNode* &root){
        if(root == NULL) return false;
        
        if(root->left == NULL and root->right == NULL){
            if(root->val == 1) return true;
            return false;
        }
        
        bool left = dfs(root->left);
        if(left == false) root->left = NULL;
        
        bool right = dfs(root->right);
        if(right == false) root->right = NULL;
        
        return root->val == 1 || left || right;
    }
    
    TreeNode* pruneTree(TreeNode* root) {
        bool isPrune = dfs(root);
        return isPrune ? root : NULL;
    }
};