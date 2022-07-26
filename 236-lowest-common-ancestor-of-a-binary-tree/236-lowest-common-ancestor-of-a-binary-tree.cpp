/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    bool pf = false, qf = false;
    
    void helper(TreeNode* root, int p, int q){
        if(root == NULL) return;
        
        if(pf and qf) return;
        
        if(p == root->val) pf = true;
        if(q == root->val) qf = true;
        
        helper(root->left, p, q);
        helper(root->right, p, q);
        
    }
    
    TreeNode* res = NULL;
    
    void dfs(TreeNode* root, int p, int q){
        if(root == NULL) return;
        
        helper(root, p, q);
        
        if(pf and qf) {
            res = new TreeNode(root->val);
        }
        
        pf = false, qf = false;
        
        dfs(root->left, p, q);
        dfs(root->right, p, q);
        
        return;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root, p->val, q->val);
        return res;
    }
};

// 6 2 0 4 3 6 8 7 9