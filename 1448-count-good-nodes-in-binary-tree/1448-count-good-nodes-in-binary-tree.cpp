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
    
    int cnt = 1;
    void dfs(TreeNode* &root){
        
        if(root->left != NULL){
            if(root->val <= root->left->val) cnt++;
            root->left->val = max(root->val, root->left->val);
            dfs(root->left);    
        }
        
        if(root->right != NULL){
            if(root->val <= root->right->val) cnt++;
            root->right->val = max(root->val, root->right->val);
            dfs(root->right);    
        }
        
    }
    
    int goodNodes(TreeNode* root) {
        dfs(root);
        return cnt;
    }
};