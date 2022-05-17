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
    TreeNode* res = NULL;
    
    void dfs(TreeNode* cloned, TreeNode* target){
        if(cloned == NULL) return;
        
        if(cloned->val == target->val){
            res = cloned;
            return;            
        }
        
        dfs(cloned->left, target);
        
        dfs(cloned->right, target);
    }
    
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        dfs(cloned, target);
        return res;
    }
};