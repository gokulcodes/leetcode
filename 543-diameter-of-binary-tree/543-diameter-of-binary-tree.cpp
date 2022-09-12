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
    
    int compute(TreeNode* root, int &mx){
        if(root == NULL) return 0;
        
        int lh = compute(root->left, mx);
        int rh = compute(root->right, mx);
        mx = max(mx, lh + rh);
        
        return 1 + max(lh, rh);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        int mx = INT_MIN;
        compute(root, mx);
        return mx;
    }
};