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
    
    bool check(TreeNode* root, long long parent, string subtree){
        if(root == NULL) return true;
        
        if(subtree == "left" and root->val >= parent) return false;
        if(subtree == "right" and root->val <= parent) return false;
        
        bool left = check(root->left, root->val, "left");
        
        bool right = check(root->right, root->val, "right");
        
        return left and right;
    }
    
    long long prev = LONG_MIN;
    
    bool dfs(TreeNode* root){
        if(root == NULL) return true;
        
        bool left = dfs(root->left);

        if(prev >= root->val) return false;
        prev = root->val;
        
        bool right = dfs(root->right);
        
        return left and right;
    }
    
    
    bool isValidBST(TreeNode* root) {
        // return check(root, LONG_MAX, "");
        return dfs(root);
    }
};