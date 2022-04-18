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
    
    void traverse(TreeNode* &root, int low, int high){
        if(root == NULL) return;
        
        if(root->val < low){
            TreeNode* temp = root->right;
            root = temp;
            traverse(root, low, high);
        }else if(root->val > high){
            TreeNode* temp = root->left;
            root = temp;
            traverse(root, low, high);
        }
        
        if(root == NULL) return;
        traverse(root->left, low, high);
        traverse(root->right, low, high);
        
    }
    
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        traverse(root, low, high);
        return root;
    }
};