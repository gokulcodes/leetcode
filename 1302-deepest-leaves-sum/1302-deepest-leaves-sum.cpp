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
    int maxDepth(TreeNode* root){
        if(root == NULL) return 0;
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
    
    
    int deepestLeavesSum(TreeNode* root) {
        int height = maxDepth(root), depth = 0, totalSum = 0;
        
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            
            if(temp == NULL){
                depth++;
            }
            
            if(temp != NULL){
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
                
                if(depth + 1 == height){
                    totalSum += temp->val;
                }
            }else if(!q.empty()){
                q.push(NULL);
            }
            
        }
        
        
        return totalSum;
    }
};