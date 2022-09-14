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
    TreeNode* lca(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root == NULL) return NULL;
        
        if(p->val == root->val) return p;
        if(q->val == root->val) return q;
        
        TreeNode* left = lca(root->left, p, q);
        TreeNode* right = lca(root->right, p, q);
        
        if(left and right and left->val == p->val and right->val == q->val) return root;
        if(left and right and left->val == q->val and right->val == p->val) return root;
        if(left and !right) return left;
        if(!left and right) return right;
        
        return NULL;
        
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return lca(root, p, q);
    }
};