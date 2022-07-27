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

// O(N) Time | O(N) Space

class Solution {
public:
    
    vector<int> preorder;
    
    void dfs(TreeNode* &root){
        if(root == NULL) return;
        preorder.push_back(root->val);
        
        dfs(root->left);
        dfs(root->right);
    }
    
    TreeNode* buildTree(int i){
        if(i >= preorder.size()) return NULL;
        
        TreeNode* root = new TreeNode(preorder[i]);
        
        root->left = NULL;
        root->right = buildTree(i + 1);
        
        return root;
    }
    
    
    void flatten(TreeNode* root) {
        
        if(!root) return;
        
        dfs(root);
        
        root->right = buildTree(1);
        root->left = NULL;
        
    }
};