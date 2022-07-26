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
    
    // bool left = 0, right = 0, mid = 0;
    
    TreeNode* res = NULL;
    
    bool dfs(TreeNode* root, int p, int q){
        if(root == NULL) return 0;
        
        bool left = dfs(root->left, p, q);
        bool right = dfs(root->right, p, q);
        
        bool mid = (root->val == p || root->val == q);
        // cout << mid << " " <<  left  << " " << right << endl;
        
        if(mid + left + right >= 2){
            res = root;
        }
        
        if(mid) return 1;
        if(right) return 1;
        if(left) return 1;
        
        return 0;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root, p->val, q->val);
        return res;
    }
};