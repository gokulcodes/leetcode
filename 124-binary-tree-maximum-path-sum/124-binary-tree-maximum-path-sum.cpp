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
    
    int dfs(TreeNode* root, int &mx){
        if(root == NULL) return 0;
        
        int left = dfs(root->left, mx);
        int right = dfs(root->right, mx);
        left = max(0, left), right = max(0, right);
        
        mx = max(mx, root->val + (left + right));
        
        return root->val + max(left, right);
    }
    
    int maxPathSum(TreeNode* root) {
        int mx = INT_MIN;
        dfs(root, mx);
        return mx;
    }
};