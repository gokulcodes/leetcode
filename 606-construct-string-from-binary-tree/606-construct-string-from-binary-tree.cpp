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
    
    string construct(TreeNode* root){
        if(root == NULL) return "";
        if(root->left == NULL and root->right == NULL) return to_string(root->val);
        
        string s = to_string(root->val), left = "", right = "";
        
        // if(root->left != NULL) 
            left = "(" + construct(root->left) + ")";
        if(root->right != NULL) 
            right = "(" + construct(root->right) + ")";
        
        return s + left + right;
    }
    
    string tree2str(TreeNode* root) {
        return construct(root);
    }
};