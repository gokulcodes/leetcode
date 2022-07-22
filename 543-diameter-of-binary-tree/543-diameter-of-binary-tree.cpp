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
    
    int maxDepth(TreeNode* root){
        if(root == NULL) return 0;
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
    
    int res = INT_MIN;
    
    void diameter(TreeNode* root){
        if(root == NULL) return;
        int mx = maxDepth(root->left);
        int mn = maxDepth(root->right);
        
        res = max(res, mx + mn);
        
        diameter(root->left);
        diameter(root->right);
        
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        diameter(root);
        return res;
        
    }
};