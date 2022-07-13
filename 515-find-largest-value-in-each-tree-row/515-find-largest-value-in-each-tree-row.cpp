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
    vector<int> largestValues(TreeNode* root) {
        
        queue<TreeNode*> q;
        q.push(root);
        
        vector<int> res;
        if(root == NULL) return res;
        
        while(!q.empty()){
            
            int mx = INT_MIN, cnt = q.size();
            
            while(cnt--){
                
                TreeNode* top = q.front();
                q.pop();
                
                mx = max(top->val, mx);
                
                if(top->left != NULL){
                    q.push(top->left);
                }
                
                if(top->right != NULL){
                    q.push(top->right);
                }
                
            }
            
            res.push_back(mx);
            
        }
        
        return res;
    }
};