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
    int sum = 0;
    
    void dfs(TreeNode* root, int parent, int gp){
        
        if(root == NULL) return;
        
        if(gp % 2 == 0) sum += root->val;
        
        dfs(root->left, root->val, parent);
        dfs(root->right, root->val, parent);
        
    }
    
    int sumEvenGrandparent(TreeNode* root) {
        dfs(root, -1, -1);
        return sum;
    }
};